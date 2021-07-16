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

struct req{
    int l;
    char t;
};
req arr[105];

ll x(string s, int n, int a, int b){
    arr[0].l = 1;
    arr[0].t = s[0];
    int c=0;
    int t=1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            arr[c].l = t;
            arr[++c].t = s[i];
            arr[c].l = 1;
            t=1;
        }
        else{
            t++;
        }
    }
    if(s[n-1]==s[n-2]){
            arr[c].l = t;
    }
    int k0=0, k1=0;
    for(int i=0;i<=c;i++){
        if(arr[i].t=='0'){
            k0++;
        }
        else{
            k1++;
        }
    }
    if(k0<(c+1)){
        k0++;
    }
    if(k1<(c+1)){
        k1++;
    }
    return min(k0, k1)*b;
}
void Solution(){ 
    ll n,a,b; cin >> n >> a >> b;
    string s; cin >> s;
    ll ans = n*a;
    if(n==1){
        ans+=b;
    }
    else if(b>=0){
        ans+=(b*n);
    }
    else{
        ans+=x(s,n,a,b);
    }
    cout << ans << endl;
}

int main() {
    fast;
    int T;
    cin >> T;
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

