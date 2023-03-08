/*
References: 

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

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
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int,int> mii;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os; // find_by_order, order_of_key (#less than key)
typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> oms; // ordered_multiset
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

#define scn(x) cin >> x
#define scna(a) for(int i=0; i<n; i++){cin >> a[i];}
#define pr(x) cout << x << endl
#define pra(a) for(auto x:a){cout << x << " ";}nl

ll mod = 1000000007;

int dp[100005][3];

void solve(int xx){ 
    int n; cin >> n;
    vpii a(n);
    fr(i,0,n,1){
        cin >> a[i].ff >> a[i].sc;
    }
    if(n==1){
        pr(1); return;
    }
    a.pb({INT_MAX,0});
    dp[0][0] = 1; // left
    dp[0][2] = 0; // don't
    if((a[0].ff+a[0].sc)<a[1].ff){ // right
        dp[0][1] = 1;
    }
    // cout << 1 << " " << 1 << " " << 0 << endl;
    fr(i,1,n,1){
        int left = a[i].ff-a[i].sc;
        int right = a[i].ff+a[i].sc;
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-1][2];
        if(a[i-1].ff<left){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2])+1;
            // If pichle tree ko right me giraya h then segment will get extended, check for that too
            if((a[i-1].ff+a[i-1].sc)<left){
                dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
            }
        }
        if(right<a[i+1].ff){
            dp[i][1] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]})+1;
        }
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
// kunal0403