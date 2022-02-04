#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
typedef pair<int, int> pii;
typedef unordered_map<int, int> umii;

typedef unordered_set<int> usi;

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

/*

*/
void solve(int xx){ 
    int n,m,q; cin >> n >> m >> q;
    string s,t; cin >> s >> t;
    string x = t+'$'+s;
    vi pi(n+m+1,0);
    fr(i,1,n+m+1,1){
        int j = pi[i-1];
        while(j>0 && x[i]!=x[j]){
            j = pi[j-1];
        }
        if(x[i]==x[j]){
            j++;
        }
        pi[i] = j;
    }
    int dp[n+2]; int c = 1;
    dp[0] = 0;
    fr(i,m+1,n+m+1,1){
        dp[c] = dp[c-1]+(pi[i]==m);
        c++;
    } int l,r;
    // fr(i,1,n+1,1){
    //     cout << dp[i] << " ";
    // }nl;
    while(q--){
        cin >> l>>r;
        l+=(m-2);
        if(r>=l){
            cout << max(0, dp[r]-dp[l]) << endl;
        }
        else{
            pr(0);
        }
    }
}

int main() {
    fast;
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
