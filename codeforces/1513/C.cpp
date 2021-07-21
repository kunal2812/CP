#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
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

int v[10][200001];
int arr[10];
unordered_map<char, ll> mp;

ll perform1(){
    for(int j=0;j<=9;j++){
        if(j==0){
            arr[0] = mp[9+'0']%mod;
            arr[1] = mp[9+'0']%mod;
            continue;
        }
        arr[j]%=mod;
        arr[j] += (mp[j-1+'0']%mod);
        arr[j]%=mod;
    }
    ll ans=0;
    for(int j=0;j<=9;j++){
        mp[j+'0'] = arr[j]%mod;
        ans+=mp[j+'0'];
        ans%=mod;
        arr[j] = 0;
    }
    return ans;
}

void init(){ 
    mp.reserve(1024); mp.max_load_factor(0.25);
    int k = 0;
    string n = "";
    n+=(k+'0');
    for(int i=0;i<n.length();i++){
        mp[n[i]]++;
    }
    for(int i=0;i<200001;i++){
        v[k][i] = perform1();
    }
    for(int j=1;j<=9;j++){
        for(int k=0;k<(200000);k++){
            v[j][k] = v[j-1][k+1];
        }
        v[j][200000] = perform1();
    }
}

void Solution(){
    int m;
    string n; cin >> n; cin >> m;
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout << v[i][j] << " ";
    //     }nl;
    // }
    ll ans=0;
    for(int i=0;i<n.length();i++){
        ans+=v[n[i]-'0'][m-1];
        ans%=mod;
    }
    cout << ans << endl;
}

int main() {
    fast;
    int T;
    init();
    cin >> T;
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

