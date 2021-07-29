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

const string t = "abacaba";
int count(string s){
    int n = s.length(); int cnt=0;
    for(int i=0;i<n;i++){
        if(s.substr(i,7)==t){
            cnt++;
        }
    }
    return cnt;
}

void Solution(){ 
    int n; cin >> n;
    string str,s; cin >> str;
    int idx=0;
    int ct=0;
    auto x = str.find(t);
    if(x!=string::npos){
        for(int i=0;i<n;i++){
            if(i==x){
                i+=7;
            }
            if(str[i]=='?'){
                str[i] = 'z';
            }
        }
        if(count(str)==1){
            cout << "YES" << endl;
            cout << str << endl;
            return;
        }
        else{
            no;
        }
    }
    for(int i=0;i<n;i++){
        s = str;
        idx=0;
        for(int j=i;j<n;j++){
            if(idx<=6 && (s[j]=='?' || s[j]==t[idx])){
                s[j] = t[idx]; idx++;
            }
        }
        // cout << s << endl;
        x = s.find(t);
        if(x!=string::npos){
            for(int i=0;i<n;i++){
                if(i==x){
                    i+=7;
                }
                if(str[i]=='?'){
                    s[i] = 'z';
                }
            }
            if(count(s)==1){
                cout << "YES" << endl;
                cout << s << endl;
                return;
            }
        }
    }
    x = s.find(t);
    if(x==string::npos){
        no;
    }
    cout << "YES" << endl;
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

