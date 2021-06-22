#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
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

umci m;
vi graph[200005];
vector<bool> vis;
string s;
void dfs(int node){
    vis[node] = true;
    m[s[node]]++;
    for(auto x:graph[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}
void Solution(){
    int n,k;
    cin >> n >> k;
    cin >> s;
    m.clear();
    vis.clear();
    vis.resize(n+5);
    for(int i=0;i<n-k;i++){
        if(i!=(k+i)){
            graph[i].pb(k+i);
            graph[k+i].pb(i);
        }
        if(i!=(n-i-1)){
            graph[i].pb(n-i-1);
            graph[n-i-1].pb(i);
        }
    }
        
    int ans=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            m.clear();
            dfs(i);
            int tot = 0;
            int maxm = 0;
            for(auto x:m){
                tot+=x.sc;
                maxm = max(maxm, x.sc);
            }
            ans += (tot-maxm);
        }
    }
    cout << ans << endl;
    for(int i=0;i<n;i++){
        graph[i].clear();
    }
    s.clear();
    m.clear();
}

int main() {
    fast;
    int T;
    cin >> T;
    while(T!=0){
        Solution();    
        T--;
    }
    return 0;
}

