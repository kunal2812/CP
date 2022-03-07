#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

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

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

/*

*/
vi graph[100005];


void solve(int xx){ 
    int n,m,k,s; cin >> n >> m >> k >> s;
    vector<vi> dist(n+1, vi(k+1, INT_MAX));
    vi a(n); unordered_map<int, vi> mp;
    int x;
    fr(i,0,n,1){
        cin >> x; mp[x].pb(i+1);
    }
    int u,v;
    fr(i,0,m,1){
        cin >> u >> v;
        graph[u].pb(v); graph[v].pb(u);
    }
    vector<bool> vis(n+1, false);
    for(auto x:mp){
        queue<int> q;
        for(auto y:x.sc){
            dist[y][x.ff] = 0;
            q.push(y);
        }
        while(!q.empty()){
            int t = q.front(); q.pop();
            vis[t] = true;
            for(auto u:graph[t]){
                if(!vis[u]){
                    q.push(u);
                    dist[u][x.ff] = min(dist[t][x.ff]+1, dist[u][x.ff]);
                }
            }
        }
        fr(i,1,n+1,1){
            vis[i] = false;
        }
    }
    for(int i=1; i<=n; i++){
        sort(dist[i].begin()+1, dist[i].end());
        int ans = 0;
        fr(j,1,s+1,1){
            ans+=dist[i][j];
        }
        cout << ans <<  " ";
    }nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
