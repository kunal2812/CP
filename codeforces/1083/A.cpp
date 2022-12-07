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

typedef priority_queue<ll> pqmax;
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
ll val[300005];
vpii tr[300005];
ll dp[300005];
ll ans;
void dfs(int x, int p){
    pqmax pq;
    for(auto t:tr[x]){
        int u = t.ff;
        ll w = t.sc;
        if(u==p){
            continue;
        }
        dfs(u,x);
        pq.push(dp[u]-w);
        dp[x] = max(dp[x], dp[u]+val[x]-w);
    }
    ll c = 0;
    if(pq.size()>=2){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        c = a+b+val[x];
    }
    dp[x] = max(dp[x],val[x]);
    ans = max({ans,c,dp[x]});
}
void solve(int xx){ 
    int n; cin >> n;
    fr(i,1,n+1,1){
        cin >> val[i];
    }
    fr(i,1,n,1){
        int u,v,w; cin >> u >> v >> w;
        tr[u].pb({v,w});
        tr[v].pb({u,w});
    }
    ans = 0;
    dfs(1,-1);
    // fr(i,1,n+1,1){
    //     cout << dp[i] << " ";
    // }nl;
    pr(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
