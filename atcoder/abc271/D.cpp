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
typedef vector<vll> vvl;
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
#define scna(x,a,b) for(int i=a; i<=b; i++){cin >> x[i];}
#define pr(x) cout << x << endl
#define pra(a) for(auto x:a){cout << x << " ";}nl

ll mod = 1000000007;

/*

*/
string ans2 = "";
int rec(int i, int s, string &ans, vi &a, vi &b, vvi &dp){
    if(i>=a.size()){
        if(s==0){
            ans2 = ans;
            return 1;
        }
        return 0;
    }
    else if(s<0){
        return 0;
    }
    else if(dp[i][s]!=-1){
        return dp[i][s];
    }
    else{
        ans+='H';
        if(rec(i+1,s-a[i],ans,a,b,dp)==1){
            return dp[i][s] = 1;
        }
        ans.ppb();
        ans+='T';
        if(rec(i+1,s-b[i],ans,a,b,dp)==1){
            return dp[i][s] = 1;
        }
        ans.ppb();
        return dp[i][s] = 0;
    }
}

void solve(int xx){ 
    int n,s; cin >> n >> s;
    vi a(n),b(n);
    fr(i,0,n,1){
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> dp(n+1, vi(s+1,-1));
    string ans = "";
    if(rec(0,s,ans,a,b,dp)==0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
        pr(ans2);
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
