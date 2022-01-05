#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
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
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
// m.reserve(1024);
// m.max_load_factor(0.25);
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

#define printA(a) for(auto x:a){ cout << x << " "; }nl;
// To rotate an array
// rotate(v.begin(), v.end()+k, v.end())

// To fill consecutive values in a vector
// iota(all(v),1);

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

set<pii> visited;
map<int, set<int>> mapx, mapy;
map<pii, int> mines;

int minm = INT_MAX;

void dfs(pii x, int k){
    visited.insert(x); minm = min(minm, mines[x]);
    int xx,yy; vi remx, remy;
    if(mapx[x.ff].size()>0){
        for(auto itr = mapx[x.ff].begin(); itr!=mapx[x.ff].end(); itr++){
            xx = x.ff; yy = *itr;
            if(abs(yy-x.sc)<=k && visited.find({xx,yy})==visited.end()){
                dfs({xx,yy},k); remx.pb(yy);
                // cout << "Child: " << xx << " " << yy << endl;
            }
        }
        for(auto t:remx){
            mapx[x.ff].erase(t);
        }
    }
    if(mapy[x.sc].size()>0){
        for(auto itr = mapy[x.sc].begin(); itr!=mapy[x.sc].end(); itr++){
            xx = *itr; yy = x.sc;
            if(abs(xx-x.ff)<=k && visited.find({xx,yy})==visited.end()){
                dfs({xx,yy},k); remy.pb(xx);
                // cout << "Child: " << xx << " " << yy << endl;
            }
        }
        for(auto t:remy){
            mapy[x.sc].erase(t);
        }
    }
}

void Solution(int xx){ 
    int n,k; cin >> n >> k;
    visited.clear(); mines.clear(); mapx.clear(); mapy.clear();
    int x,y,t;
    fr(i,0,n,1){
        cin >> x >> y >> t;
        mines[{x,y}] = t;
        mapx[x].insert(y);
        mapy[y].insert(x);
    }
    vi timer;
    for(auto x:mines){
        minm = INT_MAX;
        if(visited.find(x.ff)==visited.end()){
            // cout << "Parent: " << x.ff.ff << " " << x.ff.sc << endl;
            dfs(x.ff, k);
            timer.pb(minm);
        }
    }
    sorta(timer);
    // for(auto x:timer){
    //     cout << x << " ";
    // }nl;
    int i = 0, j = timer.size()-1, ans = 0;
    while(i<=j){
        while(timer[i]==ans){
            i++;
        }
        j--;
        ans++;
    }
    pr(max(0,ans-1));
}

int main() {
    fast;
    int t, i=0;
    cin >> t;
    while(t--){
        Solution(++i);
    }
    return 0;
}
