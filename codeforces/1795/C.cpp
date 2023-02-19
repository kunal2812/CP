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
void solve(int xx){ 
    int n; cin >> n;
    vll a(n), b(n), ans(n,0), p(n,0), d(n,0);
    fr(i,0,n,1){
        cin >> a[i];
    }
    fr(i,0,n,1){
        cin >> b[i];
        p[i]+=b[i];
        if(i>0){
            p[i]+=p[i-1];
        }
    }
    fr(i,0,n,1){
        ll t = ((i-1)>=0)?p[i-1]:0;
        int j = upper_bound(p.begin()+i, p.end(), (ll)a[i]+t)-p.begin()-1;
        d[i]++;
        if((j+1)<n){
            d[j+1]--;
        }
        // cout << i << " " << j << endl;
        ll k = (j<0)?0:p[j];
        if((j+1)<n){
        ans[j+1]+=(a[i]-(ll)(k-t));
        }
    }
    // cout << d[0] << " ";
    fr(i,1,n,1){
        d[i]+=d[i-1];
        // cout << d[i] << " ";
    }
    // nl;
    fr(i,0,n,1){
        ans[i]+=((ll)d[i]*b[i]);
        cout << ans[i] << " ";
    }
    nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
