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
ll ans = 0;
bool vis[200005];
pair<ll,ll> dp[200005];

void dfs(int x, string &s, int p){
    dp[x] = {0,0};
    for(auto t:graph[x]){
        if(t!=p){
            dfs(t, s, x);
            dp[x].ff+=dp[t].ff;
            dp[x].sc+=dp[t].sc;
        }
    }
    if(s[x-1]=='W'){
        dp[x].sc++;
    }
    else{
        dp[x].ff++;
    }
    if(dp[x].ff==dp[x].sc){
        ans++;
    }
}


void solve(int xx){ 
    int n; cin >> n;
    ans = 0;
    fr(i,1,n+1,1){
        vis[i] = false;
        graph[i].clear(); dp[i] = {0,0};
    }
    fr(i,2,n+1,1){
        ll x;cin >> x;
        graph[i].pb(x); graph[x].pb(i);
    }
    string s; cin >> s;
    dfs(1,s,-1);
    pr(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
