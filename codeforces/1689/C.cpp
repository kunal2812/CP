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
vi tr[300005];
int dp[300005];
bool vis[300005];
void dfs(int x, int p){
    if(vis[x]){
        return;
    }
    vis[x] = true;
    for(auto u:tr[x]){
        if(u==p){
            continue;
        }
        dfs(u,x);
        dp[x]+=dp[u];
    }
    dp[x]+=1;
}

int recur(int root, int p, vi &ans){
    if(tr[root].size()==1){
        return 0;
    }
    else if(tr[root].size()==2){
        int t = tr[root][0];
        if(t==p){
            t = tr[root][1];
        }
        return dp[t]-1;
    }
    else if(ans[root]!=-1){
        return ans[root];
    }
    else{
        int t = tr[root][2];
        int l = tr[root][0], r = tr[root][1];
        if(l==p){
            swap(l,t);
        }
        if(r==p){
            swap(r,t);
        }
        return ans[root] = max(dp[l]-1+recur(r,root,ans),dp[r]-1+recur(l,root,ans));
    }
}
void solve(int xx){ 
    int n; cin >> n;
    fr(i,1,n+1,1){
        dp[i] = 0; vis[i] = false; tr[i].clear();
    }
    fr(i,0,n-1,1){
        int u,v; cin >> u >> v;
        tr[u].pb(v);
        tr[v].pb(u);
    }
    tr[1].pb(-1);
    dfs(1,-1);
    vi ans(n+1,-1);
    cout << recur(1,-1,ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
