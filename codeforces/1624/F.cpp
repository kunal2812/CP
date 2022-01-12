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

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<int, int> umii;

typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

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

// To rotate an array
// rotate(v.begin(), v.end()+k, v.end())

// To fill consecutive values in a vector
// iota(all(v),1);

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

pii inter(int l1, int r1, int l2, int r2){
    return {max(l1, l2), min(r1, r2)};
}
// int ans;

// int query(int add, int n){
//         ans+=add;
//         return (ans/n);
// }

void solve(int xx){ 
    int n; cin >> n;
    int c = 1, add, d; pii np;
    int l = 1, r = n-1, m;
    while(l<=r){
        // cout << l << " " << r << endl;
        m = (l+r+1)/2;
        if((r-l)<=1){
            break;
        }
        add = n*c-m; c++; add%=n;
        cout << "+ " << add << endl;
        cin >> d;
        // d = query(add, n);
        // cout << d << endl;
        np = inter(d*n, (d+1)*n-1, l+add, r+add);
        l = np.ff; r = np.sc;
        if(c>15){
            break;
        }
    }
    if(l==r){
        cout << "! " << m << endl;
    }
    else{
        int t = ceil((dc)r/n);
        int add = n*t-r; add%=n;
        cout << "+ " << add << endl;
        cin >> d;
        // d = query(add, n);
        // cout << d << endl;
        if(d==t){
            cout << "! " << n*t << endl;
        }
        else{
            cout << "! " << n*t-1 << endl;
        }
    }
}

int main() {
    fast;
    int t, i=0;
    // cin >> ans;
    solve(++i);
    return 0;
}
