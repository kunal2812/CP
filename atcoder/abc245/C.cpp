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
bool dp[200005][2];

void solve(int xx){ 
    int n,k; cin >> n >> k;
    vi a(n), b(n);
    fr(i,0,n,1){
        cin >> a[i];
    }
    fr(i,0,n,1){
        cin >> b[i];
    }
    dp[0][0] = dp[0][1] = true;
    fr(i,1,n,1){
        if(dp[i-1][0] && abs(a[i-1]-a[i])<=k){
            dp[i][0] = true;
        }
        if(dp[i-1][0] && abs(a[i-1]-b[i])<=k){
            dp[i][1] = true;
        }
        if(dp[i-1][1] && abs(b[i-1]-b[i])<=k){
            dp[i][1] = true;
        }
        if(dp[i-1][1] && abs(b[i-1]-a[i])<=k){
            dp[i][0] = true;
        }
    }
    if(dp[n-1][0] || dp[n-1][1]){
        pr("Yes");
    }
    else{
        pr("No");
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
