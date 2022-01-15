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
typedef map<char,int> mci;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<int, int> umii;

typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

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
bool visited[100005];
vi g[100005];
bool f=false;
map<pii, pii> m;

int gi = 0;

int arr[] = {2,3};

void dfs(int node){
    
    if(g[node].size()>2){
        if(f){
            return;
        }
        f = true;
        pr(-1); return;
    }
    visited[node] = true;
    for(auto x:g[node]){
        if(visited[x]){
            continue;
        }
        else{
                // cout << node << " " << x << arr[gi] << endl;
                if(m.find({node,x})!=m.end()){
                m[{node,x}].sc = arr[gi++]; gi%=2;
                }
                else{
                m[{x,node}].sc = arr[gi++]; gi%=2;
                }
                dfs(x);
        }
    }
}
void solve(int xx){ 
    f = false; gi = 0;
    int n; cin >> n; m.clear();
    vector<int> indeg(n+1,0);
    fr(i,1,n+1,1){
        g[i].clear();
        visited[i] = false;
    }
    vector<int> ans(n-1);
    fr(i,1,n,1){
        int u,v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
        indeg[u]++; indeg[v]++;
        m[{u,v}].ff = i-1;
    }
    fr(i,1,n+1,1){
        if(indeg[i]==1){
            // cout << i << endl;
            dfs(i); break;
        }
    }
    if(!f){
        for(auto x:m){
            // cout << x.ff.ff << " " << x.sc.sc << " " << x.sc.ff << " " << x.sc.sc << endl;
            ans[x.sc.ff] =  x.second.second;
        }
        for(auto x:ans){
            cout << x << " ";
        }nl;
    }
}

int main() {
    fast;
    int t, i=0;
    cin >> t;
    while(t--){
        solve(++i);
    }
    return 0;
}
