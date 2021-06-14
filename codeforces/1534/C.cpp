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

bool visited[400005];
vi graph[400005];
void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        dfs(graph[node][i]);
    }
}

void Solution(){
    int n;
    cin >> n;
    vi u(n+2);
    vi v(n+2);
    for(int i=1;i<=n;i++){
        graph[i].clear();
        cin >> u[i];
    }
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        int a = u[i];
        int b = v[i];
        graph[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            ans = ans*2;
            ans%=mod;
            dfs(i);
        }
    }
    cout << ans << endl;
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

