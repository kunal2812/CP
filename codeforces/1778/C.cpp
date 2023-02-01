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
#define scna(a) for(int i=0; i<n; i++){cin >> a[i];}
#define pr(x) cout << x << endl
#define pra(a) for(auto x:a){cout << x << " ";}nl

ll mod = 1000000007;

/*

*/
string dd;
ll recur(int i, int k, string &a, string &b, vvi &mp, vector<vll> &dp){
    if(i>=26 || k<=0){
        ll pp = 0; ll cur = 0;
        for(int j=0; j<sz(a); j++){
            if(a[j]==b[j]){
                cur++;
            }
            else{
                pp+=((ll)cur*(cur+1))/2;
                cur = 0;
            }
        }
        pp+=((ll)cur*(cur+1))/2;
        return pp;
    }
    // else if(dp[i][k]!=-1){
    //     return dp[i][k];
    // }
    else{
        if(mp[i].empty()){
            return recur(i+1,k,a,b,mp,dp);
        }
        vector<char> tt;
        for(int j:mp[i]){
            tt.pb(a[j]);
            a[j] = b[j];
        }
        ll pp = recur(i+1,k-1,a,b,mp,dp); int c = 0;
        for(int j:mp[i]){
            a[j] = tt[c++];
        }
        return dp[i][k] = max(pp,recur(i+1,k,a,b,mp,dp));
    }
}
void solve(int xx){ 
    ll n,k; cin >> n >> k;
    string a,b; cin >> a >> b;
    vvi mp(26);
    fr(i,0,n,1){
        mp[a[i]-'a'].pb(i);
    }
    vector<vll> dp(27,vll(12,-1));
    cout << recur(0,k,a,b,mp,dp) << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
