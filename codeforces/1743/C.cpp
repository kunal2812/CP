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
int recur(int i, string &s, vi &a, vvi &dp){
    if(i>=sz(a)){
        return 0;
    }
    else if(dp[i][s[i]-'0']!=-1){
        return dp[i][s[i]-'0'];
    }
    else{
        if(s[i]=='1'){
            if((i-1)>=0 && s[i-1]=='0'){
                s[i-1] = '1'; s[i] = '0';
                int x = a[i-1]+recur(i+1,s,a,dp);
                s[i-1] = '0'; s[i] = '1';
                int y = a[i]+recur(i+1,s,a,dp);
                return dp[i][0] = max(x,y);
            }
            else{
                return dp[i][1] = a[i]+recur(i+1,s,a,dp);
            }
        }
        else{
            return dp[i][0] = recur(i+1,s,a,dp);
        }
    }
}
void solve(int xx){ 
    int n; cin >> n;
    string s; cin >> s;
    vi a(n);
    fr(i,0,n,1){
        cin >> a[i];
    }
    vvi dp(n,vi(2,-1));
    cout << recur(0,s,a,dp) << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
