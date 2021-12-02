#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
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
#define nf string::npos

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
typedef unordered_map<int, vi> umiv;
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

void Solution(int xx){ 
    int n,m; cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pii> q;
    fr(i,0,n,1){
         cin >> grid[i];
    }
    fr(i,0,n,1){
        fr(j,0,m,1){
            if(grid[i][j]=='L'){
                visited[i][j] = true;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        int x,y;
        fr(i,0,4,1){
            x = top.ff+dx[i]; y = top.sc+dy[i];
            // cout <<"xy " << x << " " << y << endl;
            if(x<0 || x>=n || y<0 || y>=m || grid[x][y]=='#' || visited[x][y]){
                continue;
            }
            int cnt=0;
            fr(j,0,4,1){
                int X = x+dx[j], Y = y+dy[j];
                // cout <<"XY " << x << " " << y << endl;
                if(X<0 || X>=n || Y<0 || Y>=m || grid[X][Y]=='#' || visited[X][Y]){
                    continue;
                }
                cnt++;
            }
            if(cnt<=1){
                // cout << x << " " << y << endl;
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
    fr(i,0,n,1){
        fr(j,0,m,1){
            if(visited[i][j] && grid[i][j]!='L'){
                cout << "+";
            }
            else{
                cout << grid[i][j];
            }
        }
        nl;
    }
    // cout << "----------------------"<< endl;
}

int main() {
    fast;
    int T;
    cin >> T;
    int i=0;
    while(T!=0){
        Solution(++i);
        T--;
    }
    return 0;
}
