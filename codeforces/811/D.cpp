#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define yes cout << "YES" << endl; return
#define no  cout << "NO" << endl; return

#define dc double
#define ff first
#define sc second
// #define endl '\n'
#define nl cout << endl

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umii;

typedef unordered_set<int> usi;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())
#define gtmin(a) *min_element(a.begin(), a.end())

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

/*

*/
void solve(int xx){ 
    int n,m; cin >> n >> m;
    vector<string> grid(n);
    vector<vi> dist(n, vector<int>(m,INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    pii dest;
    int qcnt = 0;
    fr(i,0,n,1){
        cin >> grid[i];
        fr(j,0,m,1){
            if(grid[i][j]=='F'){
                dest.ff = i; dest.sc = j;
                // cout << i << " " << j << endl;
            }
        }
    }
    pii curr = {0,0};
    vi dx, dy; vector<char> dir; pii temp;
    bool f1 = false, f2 = false;
    lr:;
    int i = curr.ff, j = curr.sc;
    if((j+1)<m && grid[i][j+1]!='*'){
        cout << 'L' << endl;
        qcnt++;
        cin >> temp.ff >> temp.sc; temp.ff--; temp.sc--;
        if(temp==dest){
            exit(0);
        }
        // Pos remains same i.e L & R works as they should
        if(temp==curr){
            dx.pb(0); dx.pb(0);
            dy.pb(-1); dy.pb(1);
            dir.pb('L'); dir.pb('R');
            if(!f1 && n>1 && grid[1][0]=='*'){
                while(temp!=dest && (temp.ff+1)<n && grid[temp.ff+1][temp.sc]!='.' && grid[temp.ff][temp.sc+1]=='.'){
                    cout << 'R' << endl; qcnt++;
                    cin >> temp.ff >> temp.sc; temp.ff--; temp.sc--;
                }
            }
        }
        else{
            dx.pb(0); dx.pb(0);
            dy.pb(1); dy.pb(-1);
            dir.pb('L'); dir.pb('R');
            if(n>1 && grid[1][0]!='*'){
                cout << "R" << endl;
                cin >> temp.ff >> temp.sc; temp.ff--; temp.sc--;
                curr = temp; f2= true;
                goto ud;
            }
            if(!f1){
                while(temp!=dest && (temp.ff+1)<n && grid[temp.ff+1][temp.sc]!='.' && grid[temp.ff][temp.sc+1]=='.'){
                    cout << 'L' << endl; qcnt++;
                    cin >> temp.ff >> temp.sc; temp.ff--; temp.sc--;
                }
            }
        }
        curr = temp;
        f2 = true;
    }
    if(curr==dest){
        exit(0);
    }
    ud:;
    i = curr.ff, j = curr.sc;
    // cout << curr.ff << "  " << curr.sc << endl;
    if((i+1)<n && grid[i+1][j]!='*'){
        cout << 'U' << endl; qcnt++;
        cin >> temp.ff >> temp.sc; temp.ff--; temp.sc--;
        if(temp==curr){
            dx.pb(-1); dx.pb(1);
            dy.pb(0); dy.pb(0);
            dir.pb('U'); dir.pb('D');
            if(!f2){
                while(temp!=dest && (temp.sc+1)<m && grid[temp.ff][temp.sc+1]!='.' && grid[temp.ff+1][temp.sc]=='.'){
                    cout << 'D' << endl; qcnt++;
                    cin >> temp.ff >> temp.sc; temp.ff--; temp.sc--;
                }
            }
        }
        else{
            dx.pb(-1); dx.pb(1);
            dy.pb(0); dy.pb(0);
            dir.pb('D'); dir.pb('U');
            if(!f2){
                while(temp!=dest && (temp.sc+1)<m && grid[temp.ff][temp.sc+1]!='.' && grid[temp.ff+1][temp.sc]=='.'){
                    cout << 'U' << endl; qcnt++;
                    cin >> temp.ff >> temp.sc; temp.ff--; temp.sc--;
                }
            }
        }
        curr = temp;
        f1 = true;
        if(!f2){
            goto lr;
        }
    }
    if(curr==dest){
        exit(0);
    }
    // for(auto c:dir){
    //     cout << c << endl;
    // }
    // cout << dx.size() << endl;
    // cout << curr.ff << " " << curr.sc << endl;
    // cout << dest.ff << " " << dest.sc << endl;
    dist[curr.ff][curr.sc] = 0;
    queue<pii> q; q.push(curr); int X,Y,x,y; 
    visited[curr.ff][curr.sc] = true;
    while(!q.empty()){
        pii t = q.front(); q.pop();
        x = t.ff, y = t.sc;
        fr(i,0,4,1){
            X = x+dx[i];
            Y = y+dy[i];
            if(X>=0 && Y>=0 && X<n && Y<m && grid[X][Y]!='*'){
                if(dist[X][Y]>(dist[x][y]+1)){
                    dist[X][Y] = dist[x][y]+1;
                }
                if(!visited[X][Y]){
                    q.push({X,Y});
                    visited[X][Y] = true;
                }
            }
        }
    }
    // fr(i,0,n,1){
    //     fr(j,0,m,1){
    //         cout << dist[i][j] << " ";
    //     }nl;
    // }
    string t = "";
    while(curr!=dest){
        int minm = INT_MAX;
        int pos;
        fr(i,0,4,1){
            X = dest.ff-dx[i];
            Y = dest.sc-dy[i];
            if(X>=0 && Y>=0 && X<n && Y<m && grid[X][Y]!='*'){
                if(dist[X][Y]<minm){
                    pos = i;
                    minm = dist[X][Y];
                }
            }
        }
        dest.ff-=dx[pos]; dest.sc-=dy[pos]; t+=dir[pos];
    }
    for(int i=sz(t)-1; i>=0; i--){
        cout << t[i] << endl;
        cin >> temp.ff >> temp.sc;
    }
    // pr(qcnt);
    // fr(i,0,n,1){
    //     fr(j,0,m,1){
    //         cout << ans[i][j] << " | ";
    //     }nl;
    // }
}

int main() {
    fast;
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
