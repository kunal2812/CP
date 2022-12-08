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
vi g[1001];
int dist1[1001];
int dist2[1001];
set<pii> st;
void solve(int xx){ 
    int n,m,s,t; cin >> n >> m >> s >> t;
    fr(i,0,m,1){
        int u,v; cin >> u>> v; st.insert({u,v});
        g[u].pb(v);
        g[v].pb(u);
    }
    fr(i,1,n+1,1){
        dist1[i] = dist2[i] = -1;
    }
    queue<int> q; 
    q.push(s); dist1[s] = dist2[t] = 0;
    while(!q.empty()){
        int f = q.front(); q.pop();
        for(auto u:g[f]){
            if(dist1[u]==-1){
                q.push(u);
                dist1[u] = dist1[f]+1;
            }
        }
    }
    q.push(t);
    while(!q.empty()){
        int f = q.front(); q.pop();
        for(auto u:g[f]){
            if(dist2[u]==-1){
                q.push(u);
                dist2[u] = dist2[f]+1;
            }
        }
    }
    int dd = dist1[t];
    int ans = 0;
    fr(i,1,n+1,1){
        fr(j,i+1,n+1,1){
            if(st.find({i,j})==st.end() && st.find({j,i})==st.end() && (dist1[i]+dist2[j]+1)>=dd && (dist1[j]+dist2[i]+1)>=dd){
                ans++;
            }
        }
    }
    pr(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
