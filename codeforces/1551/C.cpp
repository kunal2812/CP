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
    int n; cin >> n;
    vector<string> v(n);
    vector<int> a,b,c,d,e;
    for(int i=0;i<n;i++){
        cin >> v[i];
        int c1,c2,c3,c4,c5;
        c1=0; c2=0; c3=0; c4=0; c5=0;
        for(auto x:v[i]){
            if(x=='a'){
                c1++;
            }
            else if(x=='b'){
                c2++;
            }
            else if(x=='c'){
                c3++;
            }
            else if(x=='d'){
                c4++;
            }
            else{
                c5++;
            }
        }
        a.pb((2*c1)-v[i].length());
        b.pb((2*c2)-v[i].length());
        c.pb((2*c3)-v[i].length());
        d.pb((2*c4)-v[i].length());
        e.pb((2*c5)-v[i].length());
    }
    sortd(a); sortd(b); sortd(c); sortd(d); sortd(e);
    // for(auto x:a){
    //     cout << x << " ";
    // }nl;
    // for(auto x:b){
    //     cout << x << " ";
    // }nl;
    // for(auto x:c){
    //     cout << x << " ";
    // }nl;
    // for(auto x:d){
    //     cout << x << " ";
    // }nl;
    // for(auto x:e){
    //     cout << x << " ";
    // }nl;
    int curr=0;
    int i=0;
    int ans = INT_MIN;
    while((curr+a[i])>0 && i<n){
        curr+=a[i];
        i++;
    }
    ans = max(ans,i);
    i=0;
    curr=0;
    while((curr+b[i])>0 && i<n){
        curr+=b[i];
        i++;
    }
    ans = max(ans,i);
    i=0; curr=0;
    while((curr+c[i])>0 && i<n){
        curr+=c[i];
        i++;
    }
    ans = max(ans,i);
    i=0; curr=0;
    while((curr+d[i])>0 && i<n){
        curr+=d[i];
        i++;
    }
    ans = max(ans,i);
    i=0; curr=0;
    while((curr+e[i])>0 && i<n){
        curr+=e[i];
        i++;
    }
    ans = max(ans,i);
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

