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
vi ans;

void dfs(int x){
    if(vis[x]){
        return;
    }
    ans.pb(x);
    vis[x] = true;
    for(auto u:graph[x]){
        dfs(u);
    }
    ans.pb(x);
    return;
}

void solve(int xx){ 
    ans.clear();
    int n; cin >> n;
    int root = -1;
    fr(i,1,n+1,1){
        vis[i] = false;
        graph[i].clear();
    }
    int x;
    fr(i,0,n,1){
        cin >> x;
        if((i+1)==x){
            root = x;
        }
        graph[i+1].pb(x);
        graph[x].pb(i+1);
    }
    dfs(root);
    set<int> s;
    vector<vi> final;
    vi temp;
    for(auto x:ans){
        if(s.find(x)!=s.end()){
            if(sz(temp)>0){
            final.pb(temp);
            temp.clear();
            }
            continue;
        } s.insert(x);
        temp.pb(x);
    }
    cout << sz(final) << endl;
    for(auto x:final){
        cout << sz(x) << endl;
        for(auto y:x){
            cout << y << " ";
        }nl;
    }nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
