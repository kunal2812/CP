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
#define endl '\n'
#define nl cout << endl

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<int, int> umii;

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
#define gtmin(a) *min_element(a.begin(), a.end())

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve(int xx){ 
    int n,m,r,c; cin >> n >> m >> r >> c; r--; c--;
    int cnt=0;
    vector<string> g(n);
    fr(i,0,n,1){
        cin >> g[i]; 
        // cout << g[i];
        fr(j,0,m,1){
            if(g[i][j]=='B'){
                cnt++;
            }
        }
        // nl;
    }
    if(g[r][c]=='B'){
        pr(0); return;
    }
    if(cnt==0){
        pr(-1); return;
    }
    else{
        for(int i=0; i<r; i++){
            if(g[i][c]=='B'){
                pr(1);
                return;
            }
        }
        for(int i=r+1; i<n; i++){
            if(g[i][c]=='B'){
                pr(1);
                return;
            }
        }
        for(int i=0; i<c; i++){
            if(g[r][i]=='B'){
                pr(1);
                return;
            }
        }
        for(int i=c+1; i<m; i++){
            if(g[r][i]=='B'){
                pr(1);
                return;
            }
        }
    }
    pr(2);
}

int main() {
    fast;
    int t, i=0;
    cin >> t;
    while(t--){
        solve(++i);
    }
    return 0;
}
