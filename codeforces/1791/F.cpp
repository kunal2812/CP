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

/*

*/
#define N 200005
int seg[4*N], lazy[4*N];
int a[N];
int query(int si, int ss, int se, int qs, int qe){
    if(lazy[si]!=0){
        int dx = lazy[si];
        lazy[si] = 0;
        seg[si]+=dx*(se-ss+1);
        if(ss!=se){
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
    }
    if(qs>se || qe<ss){
        return 0;
    }
    if(ss>=qs && se<=qe){
        return seg[si];
    }
    int mid = (ss+se)>>1;
    return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe);
}
void update(int si, int ss, int se, int qs, int qe, int val){
    if(lazy[si]!=0){
        int dx = lazy[si];
        lazy[si] = 0;
        seg[si]+=dx*(se-ss+1);
        if(ss!=se){
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
    }
    if(qs>se || qe<ss){
        return;
    }
    if(ss>=qs && se<=qe){
        int dx = (se-ss+1)*val;
        seg[si]+=dx;
        if(ss!=se){
            lazy[2*si]+=val;
            lazy[2*si+1]+=val;
        }
        return;
    }
    int mid = (ss+se)>>1;
    update(2*si,ss,mid,qs,qe,val);
    update(2*si+1,mid+1,se,qs,qe,val);
    seg[si] = seg[2*si]+seg[2*si+1];
}
int f(int t){
    int cur = 0;
    while(t){
        cur+=(t%10);
        t/=10;
    }
    return cur;
}
void solve(int xx){ 
    int n,q; cin >> n >> q;
    fr(i,0,4*(n+1),1){
        seg[i] = lazy[i] = 0;
    }
    fr(i,1,n+1,1){
        cin >> a[i];
    }
    while(q--){
        int x; cin >> x;
        if(x==1){
            int l,r; cin >> l >> r;
            update(1,1,n,l,r,1);
        }
        else{
            int y; cin >> y;
            int p = query(1,1,n,y,y);
            int t = a[y];
            // cout << y << " " <<  p << " " << t << endl;
            while(p && t>=10){
                t = f(t);
                p--;
            }
            pr(t);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
