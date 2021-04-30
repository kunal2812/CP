#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define nl cout << endl;


typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vi> umiv;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

ll mod = 1000000007;

vector<int> graph[300005];
bool vis[200005];

int low[200005];
int disc[200005];

int lvl;

vector<pii> ans1;
vector<pii> ans2;
int bridge;
void dfs(int node, int parent){
    vis[node]=true;
    disc[node] = low[node] = ++lvl;
    for(int i=0;i<graph[node].size();i++){
        if(graph[node][i]==parent) continue;
        if(vis[graph[node][i]]){
            ans1.pb(mp(graph[node][i], node));
            low[node] = min(low[node], low[graph[node][i]]);
        }
        else{
            ans2.pb(mp(graph[node][i], node));
            dfs(graph[node][i], node);
            if(low[graph[node][i]]>disc[node]){
                bridge++;
            }
            low[node] = min(low[node], low[graph[node][i]]);
        }
    }
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, -1);
    int t = ans1.size()/2;
    if(bridge>0){
        cout << 0 << endl; return 0;
    }
    
    // cout << ans1.size() << endl;
    // cout << ans2.size() << endl;
    
    map<pii, int> mm;
    
    for(int i=0;i<ans1.size();i++){
        int x = ans1[i].sc;
        int y = ans1[i].ff;
        if(mm[mp(x, y)]!=1 && mm[mp(y,x)]!=1){
            cout << ans1[i].sc << " " << ans1[i].ff << endl;
            mm[{x, y}] = 1;
            mm[{y, x}] = 1;
        }
    }
    
    for(int i=0;i<ans2.size();i++){
        cout << ans2[i].sc << " " << ans2[i].ff << endl;
    }
}

