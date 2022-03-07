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

int dx[] = {0,1,0,-1,-1,1,-1,1};
int dy[] = {1,0,-1,0,-1,1,1,-1};


void solve(int xx){ 
    ll x0,y0,x1,y1; cin >> x0 >> y0 >> x1 >> y1;
    int n; cin >> n;
    int a,b,c; 
    map<pii, bool> vis;
    set<pii> allowed;
    map<pii, int> dist;
    vis[{x0,y0}] = vis[{x1,y1}] = false;
    fr(i,0,n,1){
        cin >> a >> b >> c;
        fr(i,b,c+1,1){
            allowed.insert({a,i});
            vis[{a,i}] = false;
            dist[{a,i}] = INT_MAX;
        }
    }
    queue<pii> q; q.push({x0,y0});
    dist[{x0,y0}] = 0;
    while(!q.empty()){
        pii t = q.front(); q.pop();
        vis[t] = true;
        fr(i,0,8,1){
            int x = t.ff + dx[i];
            int y = t.sc + dy[i];
            if(allowed.find({x,y})!=allowed.end() && !vis[{x,y}] && (dist[t]+1)<dist[{x,y}]){
                dist[{x,y}] = dist[t]+1;
                q.push({x,y});
            }
        }
    }
    if(dist.find({x1,y1})==dist.end() || dist[{x1,y1}]==INT_MAX){
        pr(-1); 
    }
    else{
        cout << dist[{x1,y1}] << endl;
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
