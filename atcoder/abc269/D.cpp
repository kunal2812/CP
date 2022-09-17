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

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os; // find_by_order, order_of_key
typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> oms; // ordered_multiset
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



set<pii> pp;

int parent[1001];

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void make(int n) {
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
}
void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b)
        swap(a, b);
    if (a != b)
        parent[b] = a;
}

bool connected(int i, int j, vector<pii> &b){
    int x = b[j].ff-b[i].ff;
    int y = b[j].sc-b[i].sc;
    if(pp.find({x,y})!=pp.end() || pp.find({-x,-y})!=pp.end()){
        return true;
    }
    return false;
}

void solve(int x){
    int n; cin >> n;
    make(n);
    vector<pii> b(n);
    fr(i,0,n,1){
        cin >> b[i].ff >> b[i].sc;
    }
    pp.insert({-1,-1});
    pp.insert({-1,0});
    pp.insert({0,-1});
    pp.insert({0,1});
    pp.insert({1,0});
    pp.insert({1,1});
    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(connected(i,j,b)){
                union_set(find(i+1),find(j+1));
            }
        }
    }
        for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(connected(i,j,b)){
                union_set(find(i+1),find(j+1));
            }
        }
    }
    set<int> st;
    for(int i=1; i<=n; i++){
        st.insert(parent[i]);
    }
    pr(sz(st));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
