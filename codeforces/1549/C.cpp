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

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())

#define printA(a) for(auto x:a){ cout << x << " "; }nl;
// To rotate an array
// rotate(v.begin(), v.end()+k, v.end())

// To fill consecutive values in a vector
// iota(all(v),1);


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
    int n,f; cin >> n >> f;
    unordered_map<int, set<int>> m;
    vector<int> cnt(n+1,0);
    int ans = n;
    for(int i=0;i<f;i++){
        int x,y; cin >> x >> y;
        if(x>y){
            swap(x,y);
        }
        m[x].insert(y);
        m[y].insert(x);
        cnt[x]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]>0){
            ans--;
        }
    }
    int q; cin >> q;
    for(int i=0;i<q;i++){
        int x,y,z;
        cin >> x;
        if(x==1){
            cin >> y >> z;
            if(y>z){
                swap(y,z);
            }
            if(cnt[y]==0){
                ans--; 
            }
            cnt[y]++;
        }
        else if(x==2){
            cin >> y >> z;
            if(y>z){
                swap(y,z);
            }
            cnt[y]--;
            if(cnt[y]==0){
                ans++;
            }
        }
        else{
            cout << ans << endl;
        }
    }
}

int main() {
    fast;
    // int T;
    // cin >> T;
    // while(T!=0){
        Solution();
        // T--;
    // }
    return 0;
}

