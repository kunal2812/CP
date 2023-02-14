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

vi ar[N];
const int maxN = 19;
int level[N] , LCA[N][maxN+1], dp[N], P[N];
 
 
int dfs(int node , int lvl , int par){
	level[node] = lvl;
	LCA[node][0] = par;
    dp[node] = 1;
	for(int child : ar[node]){
    	if(child != par){
    	    P[child] = node;
    		dp[node] += dfs(child , lvl+1 , node);
    	}
	}
	return dp[node];
}
 
 
void init(int n){
    for(int i=1;i<=n;i++){
		for(int j=0;j<=maxN;j++){
		    LCA[i][j] = -1;
        }
	}
	dfs(1 , 0 , -1);
 
	for(int i=1;i<=maxN;i++)
	{
		for(int j=1;j<=n;j++)
		if(LCA[j][i-1] != -1)
		{
			int par = LCA[j][i-1];
			LCA[j][i] = LCA[par][i-1];
		}
	}
}
 
int getLCA(int a , int b)
{
	if(level[b] < level[a]) swap(a , b);
 
	int d = level[b] - level[a];
 
	while(d > 0)
	{
		int i = log2(d);
		b = LCA[b][i];
 
		d -= 1 << i;
	}
 
	if(a == b) return a;
 
	for(int i=maxN;i>=0;i--)
	if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
	{
		a = LCA[a][i] , b = LCA[b][i];
	}
 
	return LCA[a][0];
}
 
 
int getDist(int a , int b)
{
	int lca = getLCA(a , b);
	int dist = level[a] + level[b] - 2*level[lca];
	return dist;
}

void solve(int xx){ 
    int n,q; cin >> n;
    fr(i,0,n-1,1){
        int u,v; cin >> u >> v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    cin >> q;
    init(n+1);
    while(q--){
        int u,v; cin >> u >> v;
        int dd = getDist(u,v);
        if(dd%2){
            pr(0);
        }
        else if(u==v){
            pr(n);
        }
        else if(level[u]==level[v]){
            int g = getDist(u,v); 
            g/=2; g--;
            int aa = u, bb = v;
            while(g>0){
        		int i = log2(g);
        		aa = LCA[aa][i];
        		bb = LCA[bb][i];
        		g -= 1 << i;
        	}
        	int lca = getLCA(u,v);
        	int ans = dp[lca]-dp[aa]-dp[bb];
            pr(dp[1]-dp[lca]+ans);
        }
        else{
            if(level[v] < level[u]) swap(u,v);
        	int d = dd/2; int tmp = v;
        	while(d>0){
        		int i = log2(d);
        		v = LCA[v][i];
        		d -= 1 << i;
        	}
        	d = dd/2-1;
        	while(d>0){
        		int i = log2(d);
        		tmp = LCA[tmp][i];
        		d -= 1 << i;
        	}
        	int ans = dp[v];
        	ans-=dp[tmp];
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