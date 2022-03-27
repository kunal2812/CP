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
void solve(int xx){ 
    int n,m; cin >> n >> m;
    vector<string> g(n);
    fr(i,0,n,1){
        cin >> g[i];
    }
    vector<pair<pii,pii>> ans;
    rfr(i,n-1,0,1){
        rfr(j,m-1,0,1){
            if(g[i][j]=='1'){
                if((j-1)>=0){
                    ans.pb({{i,j-1},{i,j}});
                }
                else if((i-1)>=0){
                    ans.pb({{i-1,j},{i,j}});
                }
                else{
                    pr(-1); return;
                }
            }
        }
    }
    cout << sz(ans) << endl;
    for(auto x:ans){
        cout << x.ff.ff+1 << " " << x.ff.sc+1 << " " << x.sc.ff+1 << " " << x.sc.sc+1 << endl;
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
