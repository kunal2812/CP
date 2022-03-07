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
vi graph[200005];
bool vis[200005];

int clk = 0;
vi trav;

map<int, int> mp;

int tin[200005], tout[200005];

int jk=0;

void dfs(int x){
    if(vis[x]) return;
    vis[x] = true;
    mp[x] = clk; trav.pb(x);
    clk++; tin[x] = jk++;
    for(auto t:graph[x]){
        dfs(t);
    }
    tout[x] = jk++;
}

void solve(int xx){ 
    int n,q; cin >> n >> q;
    int x;
    fr(i,2,n+1,1){
        cin >> x;
        graph[x].pb(i);
    }
    dfs(1);
    
    // fr(i,1,n+1,1){
    //     cout << tin[i] << " ";
    // }nl; 
    // fr(i,1,n+1,1){
    //     cout << tout[i] << " ";
    // }nl;
    int u,v;
    while(q--){
        cin >> u >> v;
        int i = mp[u];
        i = i+v-1;
        if(i<trav.size() && tout[u]>tin[trav[i]]){
            cout << trav[i] << endl;
        }
        else{
            pr(-1);
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
