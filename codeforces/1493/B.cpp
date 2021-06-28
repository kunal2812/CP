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

bool check(string s, int m, int h){
    unordered_set<char> cc;
    cc.insert('1'); cc.insert('0'); cc.insert('2'); cc.insert('5'); cc.insert('8');
    for(int i=0;i<s.length();i++){
        if(s[i]!=':'){
            if(cc.find(s[i])==cc.end()){
                return false;
            }
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='2'){
            s[i]='5';
        }
        else if(s[i]=='5'){
            s[i]='2';
        }
    }
    int t = s.find(':');
    string hrs = s.substr(0,t);
    string mins = s.substr(t+1,s.length()-t);
    rev(hrs);rev(mins);
    // cout << hrs << " " << mins << endl;
    if(stoi(hrs)>=m || stoi(mins)>=h){
        // cout << hrs << " " << mins  << endl;
        return false;
    }
    return true;
}

void Solution(){ 
    int h,m;
    cin >> h >> m;
    string s;
    cin >> s;
    int t = s.find(':');
    string hrs = s.substr(0,t);
    string mins = s.substr(t+1,s.length()-t);
    int hr = stoi(hrs);
    int min = stoi(mins);
    // cout << check(s) << endl;
    while(check(s,m,h)!=true){
        if((min+1)>=m && (hr+1)>=h){
            hr = 0;
            min = -1;
        }
        if((min+1)>=m){
            min = -1;
            hr++;
        }
        min++;
        string tt = to_string(hr);
        string t = "";
        if(tt.length()==1){
            t+='0';
        }
        t+=tt;
        string tt2 = to_string(min);
        string t2 = "";
        if(tt2.length()==1){
            t2+='0';
        }
        t2+=tt2;
        s = t + ':' + t2;
        // cout << s << endl;
    }
    cout << s << endl;
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