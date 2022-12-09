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
typedef vector<vll> vvl;
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
vi g[200005];
int color[200005];
vi topo;
bool dfs(int x){
    color[x] = 1;
    for(auto u:g[x]){
        if(color[u]==2){
            continue;
        }
        if(color[u]==1 || dfs(u)){
            return true;
        }
    }
    color[x] = 2;
    topo.pb(x);
    return false;
}
void solve(int xx){ 
    int n,p; cin >> n >> p;
    topo.clear();
    fr(i,1,n+1,1){
        g[i].clear(); color[i] = 0;
    }
    vpii s1,s2;
    fr(i,0,p,1){
        int t,x,y; cin >> t >> x >> y;
        if(t==1){
            g[x].pb(y);
            s1.pb({x,y});
        }
        else{
            s2.pb({x,y});
        }
    }
    fr(i,1,n+1,1){
        if(color[i]==0 && dfs(i)){
            no;
        }
    }
    pr("YES");
    mii m;
    fr(i,0,sz(topo),1){
        m[topo[i]] = n-i;
    }
    for(auto e:s2){
        if(m[e.ff]<m[e.sc]){
            s1.pb(e);
        }
        else{
            s1.pb({e.sc,e.ff});
        }
    }
    for(pii e:s1){
        cout << e.ff << " " << e.sc << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
