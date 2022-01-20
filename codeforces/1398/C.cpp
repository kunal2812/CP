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
/*
size 0 -> no subarray having single element 0
size 1 -> All elements 1 form their own subarray ans+=freq[1]
size 2 -> 11, 02,20
size 3 -> 111,102,201,300, 030, 003
1 0 0 0 0 0 2 2 3 7 2 2 0 0 0 0 8 4 9 0
1 0 0 0 0 0 3 
0 1 -1
0 1  
1  1  0  1  1
0  0 -1  0  0
1  3  3  4  6

0 1 -1
0 1  0
0 0 -1 0 0
1 2 3 4
*/
void solve(int xx){ 
    int n; cin >> n;
    string s; cin >> s;
    ll ans = 0;
    mii mp;
    int curr = 0; int i = 0; mp[0] = 1;
    while(i<n){
        curr+=(s[i]-'0'-1);
        mp[curr]++;
        i++;
    }
    for(auto t:mp){
        ans+=((ll)t.sc*(t.sc-1))/2;
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
