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

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())

ll mod = 1000000007;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void Solution(){ 
    int n; cin >> n;
    vector<vector<int>> a(n+1, vi(n+1,0));
    for(int i=1;i<=n;i++){
        cin >> a[i][i];
    }
    vi ctr(n+1,0);
    for(int i=1;i<=n;i++){
        ctr[i] = i-1;
    }
    int j = 2; int i = 1;
    while(j<=n){
        int x,y;
        usi s; s.reserve(1024); s.max_load_factor(0.25);
        for(x=j,y=1;x<=n && y<=(n-i);x++,y++){
            // cout << x << " " << y << endl;
            if(ctr[a[x-1][y]]>0 && s.find(a[x-1][y])==s.end()){
                a[x][y] = a[x-1][y];
                s.insert(a[x][y]);
                ctr[a[x-1][y]]--;
            }
            else{
                a[x][y] = a[x][y+1];
                s.insert(a[x][y]);
                ctr[a[x][y+1]]--;
            }
        }
        i++;
        j++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << a[i][j] << " ";
        }nl;
    }
}

int main() {
    fast;
    // int T;
    // cin >> T;
    // while(T!=0){
        Solution();
    //     T--;
    // }
    return 0;
}

