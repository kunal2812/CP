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
#define LOG 17

int S[N], P[N], L[N], R[N];
set<int> G[N];
int LCA[N][LOG+1];

void dfs(int node, int p, int l){
    L[node] = l;
	LCA[node][0] = p;
    for(int x:G[node]){
        if(x!=p){
            dfs(x,node,l+1);
        }
    }
}

void initLCA(int n){
	dfs(1,-1,0);
	for(int i=1;i<=LOG;i++){
		for(int j=1;j<=n;j++){
    		if(LCA[j][i-1] != -1){
    			int par = LCA[j][i-1];
    			LCA[j][i] = LCA[par][i-1];
    		}
		}
	}
}

int getLCA(int a , int b){
	if(L[b] < L[a]){
	    swap(a,b);
	}
	int d = L[b]-L[a];
	while(d>0){
		int i = log2(d);
		b = LCA[b][i];
		d -= 1 << i;
	}
	if(a==b) return a;
	for(int i=LOG;i>=0;i--){
    	if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i])){
    		a = LCA[a][i] , b = LCA[b][i];
    	}
	}
	return LCA[a][0];
}

int getDist(int a , int b){
	int lca = getLCA(a , b);
	int dist = L[a] + L[b] - 2*L[lca];
	return dist;
}

int dfs1(int node, int p){
    S[node] = 1;
    for(int x:G[node]){
        if(x!=p){
            S[node]+=dfs1(x,node);
        }
    }
    return S[node];
}

int dfs2(int node, int p, int n){
    for(int x:G[node]){
        if(x!=p && S[x]>(n/2)){
            return dfs2(x,node,n);
        }
    }
    return node;
}

void decompose(int node, int p){
    int size = dfs1(node, p);
    int centroid = dfs2(node, p, size);
    P[centroid] = p;
    for(int x:G[centroid]){
        G[x].erase(centroid); decompose(x, centroid);
    }
}

void update(int node){
    int curr = node;
    R[node] = 0;
    while(curr!=-1){
        R[curr] = min(R[curr], getDist(curr,node));
        curr = P[curr];
    }
}

int query(int node){
    int curr = node;
    int ans = INT_MAX;
    while(curr!=-1){
        ans = min(ans, R[curr]+getDist(curr,node));
        curr = P[curr];
    }
    return ans;
}

void solve(int xx){ 
    int n,m; cin >> n >> m;
    for(int i=1; i<=n; i++){
        G[i].clear();
        R[i] = n;
        P[i] = 0;
        S[i] = 0;
        L[i] = 0;
    }
    for(int i=1;i<=LOG;i++){
		for(int j=1;j<=n;j++){
    		if(LCA[j][i-1] != -1){
    			int par = LCA[j][i-1];
    			LCA[j][i] = LCA[par][i-1];
    		}
		}
	}
    fr(i,1,n,1){
        int u,v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    initLCA(n);
    decompose(1,-1);
    update(1);
    while(m--){
        int x,y; cin >> x >> y;
        if(x==1){
            update(y);
        }
        else{
            cout << query(y) << endl;
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
