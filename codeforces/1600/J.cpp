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

int grid[1001][1001];
int vis[1001][1001];

int cnt = 1;
int n,m;

void dfs(int x, int y){
    if(x>=n || y>=m || x<0 || y<0 || vis[x][y]!=0){
        return;
    }
    vis[x][y] = cnt;
    fr(i,0,4,1){
        if((grid[x][y]&(1<<i))==0){
            if(i==0){
                dfs(x,y-1);
            }
            else if(i==1){
                dfs(x+1,y);
            }
            else if(i==2){
                dfs(x,y+1);
            }
            else{
                dfs(x-1,y);
            }
        }
    }
}

void solve(int xx){ 
    cin >> n >> m;
    fr(i,0,n,1){
        fr(j,0,m,1){
            cin >> grid[i][j];
        }
    }
    fr(i,0,n,1){
        fr(j,0,m,1){
            if(vis[i][j]==0){
                dfs(i,j);
                cnt++;
            }
        }
    }
    unordered_map<int, int> mp;
    fr(i,0,n,1){
        fr(j,0,m,1){
            // cout << vis[i][j] << " ";
            mp[vis[i][j]]++;
        }
        // nl;
    }
    vi ans;
    for(auto x:mp){
        ans.pb(x.sc);
    }
    sort(all(ans),greater<int>());
    for(auto x:ans){
        cout << x <<  " ";
    }nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
