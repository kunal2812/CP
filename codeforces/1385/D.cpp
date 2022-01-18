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
// Pasing string by value adds O(n) factor
int good(string &s, int l, int r, char c, vector<map<char, int>> &freq){
    if(l==r){
        return (s[l]==c)?0:1;
    }
    int m = l+r+1; m/=2; int cnt1=0, cnt2=0;
    for(auto x:freq[m-1]){
        // cout << x.ff << " " << x.sc << endl;
        if(l!=0){
            if(x.ff!=c){
                cnt1+=(x.sc-freq[l-1][x.ff]);
            }
        }
        else{
            if(x.ff!=c){
                cnt1+=x.sc;
            }
        }
    }
    for(auto x:freq[r]){
        if(x.ff!=c){
            cnt2+=(x.sc-freq[m-1][x.ff]);
        }
    }
    return min(cnt1+good(s,m, r,c+1,freq), cnt2+good(s,l,m-1,c+1,freq));
}

void solve(int xx){ 
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = n-1;
    vector<map<char, int>> freq; map<char, int> m;
    fr(i,0,n,1){
        m[s[i]]++;
        freq.pb(m);
    }
    int ans = good(s,l,r, 'a', freq);
    pr(ans);
}

int main() {
    fast;
    int t, i=0; cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
