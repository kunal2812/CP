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
3 4
1 1 2 2
2 1 1 2
2 2 1 1

1 - (0,0) (0,1) (1,1) (1,2) (2,2) (2,3)
2 - (0,2) (0,3) (1,0) (1,3) (2,0) (2,1)

4+8+9+4+4+2
12+4+9+9+

1+2+5
1+4
3
16

0 1 2 5
1 1 3
1 1 3

*/

bool cmp(pii x, pii y){
    return x.sc<y.sc;
}

ll calc(vector<pii> &v){
    int n = v.size();
    sort(all(v));
    ll ans = 0;
    rfr(i,n-1,0,1){
        ans+=(2*i-n+1)*v[i].ff;
    }
    sort(all(v), cmp);
    rfr(i,n-1,0,1){
        ans+=(ll)(2*i-n+1)*v[i].sc;
    }
    return ans;
}

void solve(int xx){ 
   int n,m; cin >> n >> m;
   map<int, vector<pii>> mp;
   int x;
   fr(i,0,n,1){
       fr(j,0,m,1){
           cin >> x;
           mp[x].pb({i,j});
       }
   }
   ll ans = 0;
   for(auto x:mp){
       ans+=calc(x.sc);
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
