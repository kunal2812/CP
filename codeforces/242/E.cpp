#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front

#define yes cout << "YES" << endl; return
#define no  cout << "NO" << endl; return

#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef map<int,int> mii;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os; // find_by_order, order_of_key (#less than key)
typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> oms; // ordered_multiset
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

#define scn(x) cin >> x
#define scna(a) for(int i=0; i<n; i++){cin >> a[i];}
#define pr(x) cout << x << endl
#define pra(a) for(auto x:a){cout << x << " ";}nl

ll mod = 1000000007;

#define N 100005
int seg[4*N][20], lazy[4*N][20];
int a[N];
void build(int i, int si, int ss, int se){
    if(ss==se){
        seg[si][i] = (a[ss]&1<<i)?1:0;
        return;
    }
    int mid = (ss+se)>>1;
    build(i,2*si,ss,mid);
    build(i,2*si+1,mid+1,se);
    seg[si][i] = seg[2*si][i]+seg[2*si+1][i];
}
int query(int i, int si, int ss, int se, int qs, int qe){
    if(lazy[si][i]){
        seg[si][i]=(se-ss+1)-seg[si][i];
        if(ss!=se){
            lazy[2*si][i]^=1;
            lazy[2*si+1][i]^=1;
        }
        lazy[si][i] = 0;
    }
    if(qs>se || qe<ss){
        return 0;
    }
    if(ss>=qs && se<=qe){
        return seg[si][i];
    }
    int mid = (ss+se)>>1;
    return query(i,2*si,ss,mid,qs,qe)+query(i,2*si+1,mid+1,se,qs,qe);
}
void update(int i, int si, int ss, int se, int qs, int qe, int val){
    if(lazy[si][i]!=0){
        seg[si][i]=(se-ss+1)-seg[si][i];
        if(ss!=se){
            lazy[2*si][i]^=1;
            lazy[2*si+1][i]^=1;
        }
        lazy[si][i] = 0;
    }
    if(qs>se || qe<ss){
        return;
    }
    if(ss>=qs && se<=qe){
        if(val){
            seg[si][i] = (se-ss+1)-seg[si][i];
        }
        if(ss!=se){
            lazy[2*si][i]^=val;
            lazy[2*si+1][i]^=val;
        }
        lazy[si][i] = 0;
        return;
    }
    int mid = (ss+se)>>1;
    update(i,2*si,ss,mid,qs,qe,val);
    update(i,2*si+1,mid+1,se,qs,qe,val);
    seg[si][i] = seg[2*si][i]+seg[2*si+1][i];
}
void solve(int xx){
    int n; cin >> n;
    fr(i,1,n+1,1){
        cin >> a[i];
    }
    fr(i,0,20,1){
        build(i,1,1,n);
    }
    int q; cin >> q;
    while(q--){
        int x,l,r; cin >> x >> l >> r;
        if(x==2){
            ll d; cin >> d;
            fr(i,0,20,1){
                update(i,1,1,n,l,r,(d&(1<<i))?1:0);
            }
        }
        else{
            ll ans = 0;
            fr(i,0,20,1){
                ans+=(ll)query(i,1,1,n,l,r)*(1<<i);
            }
            pr(ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
