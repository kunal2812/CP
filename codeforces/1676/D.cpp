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

int dx[4] = {-1,1,1,-1};
int dy[4] = {1,-1,1,-1};

ll find(int x, int y, vector<vll> &a){
    ll ans = 0; int n = sz(a); int m = a[0].size();
    ans+=(ll)a[x][y];
    fr(i,0,4,1){
        int t1 = x+dx[i], t2 = y+dy[i];
        while(t1>=0 && t2>=0 && t1<=(n-1) && t2<=(m-1)){
            ans+=(ll)a[t1][t2];
            t1+=dx[i]; t2+=dy[i];
        }
    }
    // cout << x << " " << y << " " << ans << endl;
    return ans;
}

void solve(int xx){ 
    int n,m; cin >> n >> m;
    vector<vll> a(n,vll(m));
    ll ans = LONG_LONG_MIN; 
    fr(i,0,n,1){
        fr(j,0,m,1){
            cin >> a[i][j];
        }
    }
    fr(i,0,n,1){
        fr(j,0,m,1){
            ans = max(ans,find(i,j,a));
        }
    }
    pr(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
