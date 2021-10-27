#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl;

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vi> umiv;
// m.reserve(1024);
// m.max_load_factor(0.25);
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

#define printA(a) for(auto x:a){ cout << x << " "; }nl;
// To rotate an array
// rotate(v.begin(), v.end()+k, v.end())

// To fill consecutive values in a vector
// iota(all(v),1);

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
struct item{
    int l,r,d;
};
void Solution(int xx){ 
    int n,m,k; cin >> n >> m >> k;
    vll a(n+1), que(m+2, 0), op(n+2, 0), pref1(n+2), pref2(m+2);
    vector<item> v(m+1);
    fr(i, 1, n+1, 1){
        cin >> a[i];
    }
    fr(i,1,m+1,1){
        cin >> v[i].l >> v[i].r >> v[i].d;
    }
    fr(i, 0, k, 1){
        int x,y; cin >> x >> y;
        que[x]++; que[y+1]--;
    }
    fr(i,1,m+1,1){
        pref2[i] = pref2[i-1]+que[i];
        // cout << pref2[i] << " ";
    }
    fr(i,1,m+1,1){
        int d = v[i].d;
        op[v[i].l]+=(pref2[i]*d); op[v[i].r+1]-=(pref2[i]*d);
    }
    fr(i,1,n+1,1){
        pref1[i] = pref1[i-1]+op[i];
    }
    fr(i,1,n+1,1){
        cout << a[i]+pref1[i] << " ";
    }nl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    int T;
    // cin >> T;
    int i=0;
    // while(T!=0){
        Solution(++i);
    //     T--;
    // }
    return 0;
}
