#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
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

ll mod = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

/*
4 5
01001
10101
00001 * 3
01000


*/
void solve(int xx){ 
    int n,m; cin >> n >> m;
    string a,b; cin >> a >> b;
    if(n!=m){
        string t = "";
        int i = abs(n-m);
        while(i--){
            t+='0';
        }
        if(n<m){
            t+=a;
            a = t;
        }
        else{
            t+=b;
            b = t;
        }
        n = max(n,m);
        m = max(n,m);
    }
    // cout << a << " " << b << endl;
    vi pref(n,0);
    pref[0] = b[0]=='1';
    fr(i,1,n,1){
        if(b[i]=='1'){
            pref[i] = pref[i-1] + 1;
        }
        else{
            pref[i] = pref[i-1];
        }
    }
    ll ans = 0;
    ll p = 1;
    rfr(i,n-1,0,1){
        if(a[i]=='1'){
            ans+=(((ll)(p%mod)*(pref[i]%mod))%mod);
            ans%=mod;
        }
        p*=2;
        p%=mod;
    }
    pr(ans);
}

int main() {
    fast;
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
