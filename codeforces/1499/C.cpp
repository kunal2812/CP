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

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve(int xx){ 
    ll n; cin >> n;
    vll c(n);
    fr(i,0,n,1){
        cin >> c[i];
    }
    ll cnt_even = 1, cnt_odd=1;
    ll odd_cost = c[1], even_cost = c[0];
    ll min_odd = c[1], min_even = c[0];
    ll cost = odd_cost+even_cost+min_odd*(n-cnt_odd)+min_even*(n-cnt_even);
    ll ans = cost; 
    // cout << 1 << " " << cost << endl;
    fr(i,2,n,1){
        if(i%2){
            min_odd = min(min_odd, c[i]); cnt_odd++;
            odd_cost+=c[i];
        }
        else{
            min_even = min(min_even, c[i]); cnt_even++;
            even_cost+=c[i];
        }
        cost = odd_cost+even_cost+min_odd*(n-cnt_odd)+min_even*(n-cnt_even);
        // cout << i << " " << cost << endl;
        ans = min(ans, cost);
    }
    pr(ans);
}

int main() {
    fast;
    int t, i=0; cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
