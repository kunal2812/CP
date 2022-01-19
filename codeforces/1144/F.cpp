#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
typedef map<int,int> mii;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umii;

typedef unordered_set<int> usi;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())
#define gtmin(a) *min_element(a.begin(), a.end())

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vi g[200005];
bool vis[200005];
int color[200005];
int dist[200005];
bool isBipartite = true;

void dfs(int node){
    for(auto x:g[node]){
        if(color[x]==color[node]){
            isBipartite = false; return;
        }
        if(color[x]==0){
            color[x] = (color[node]==1)?2:1;
            dfs(x);
        }
    }
}

void solve(int xx){ 
    int n,m; cin >> n >> m;
    int u,v;
    vector<pii> edges(m); map<pii, int> mp;
    fr(i,0,m,1){
        cin >> u >> v;
        edges[i].ff = u; edges[i].sc = v;
        g[u].pb(v); g[v].pb(u);
        mp[{u,v}] = 0;
    }
    color[1] = 1; dfs(1); 
    if(!isBipartite){
        no;
    }
    queue<int> q; q.push(1); dist[1] = 0;
    while(!q.empty()){
        int t = q.front(); q.pop();
        vis[t] = true;
        for(auto k:g[t]){
            if(!vis[k]){
                dist[k] = dist[t]+1;
                q.push(k);
                if(mp.find({t,k})!=mp.end()){
                    mp[{t,k}] = dist[k]%2;
                }
                else{
                    mp[{k,t}] = (dist[k]+1)%2;
                }
            }
        }
    }
    pr("YES");
    for(auto p:edges){
        cout << mp[p];
    }nl;
}

int main() {
    fast;
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
