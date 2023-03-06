/* 
References:

*/
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
typedef vector<vll> vvll;
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

/*

*/

#define N 200005
ll m1 = 1e9+7;
ll m2 = 998244353;

vi T1[N];
pll Hash[N];
int par[N];

void dfs(int x, int p, ll p1, ll p2){
    Hash[x] = {1,1};
    par[x] = p;
    for(auto u:T1[x]){
        if(u!=p){
            dfs(u,x,p1,p2);
            Hash[x].ff = (((Hash[x].ff*(sz(T1[u])+Hash[u].ff))%m1)*p1)%m1;
            Hash[x].sc = (((Hash[x].sc*(sz(T1[u])+Hash[u].sc))%m2)*p2)%m2;
        }
    }
}

bool isSymmetric(int z){
    map<pll,int> mp;
    for(auto u:T1[z]){
        if(par[z]!=u){
            mp[Hash[u]]++;
        }
    }
    pll pp = {-1,-1};
    int cnt = 0;
    for(auto x:mp){
        if(x.sc%2){
            cnt++;
            pp = x.ff;
        }
    }
    if(cnt>1){
        return false;
    }
    if(cnt==0){
        return true;
    }
    for(auto u:T1[z]){
        if(par[z]==u){
            continue;
        }
        if(Hash[u]==pp){
            return isSymmetric(u);
        }
    }
}

void solve(int xx){ 
    int n; cin >> n;
    fr(i,0,n+1,1){
        T1[i].clear();
        Hash[i] = {0,0};
    }
    fr(i,1,n,1){
        int u,v; cin >> u >> v;
        T1[u].pb(v); T1[v].pb(u);
    }
    dfs(1,-1,200177,500197);
    if(isSymmetric(1)){
        yes;
    }no;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
// kunal0403