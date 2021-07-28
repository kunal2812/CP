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


void Solution(){ 
    int n; cin >> n;
    string s,t; cin >> s >> t;
    vi v;
    int j = n-1;
    while(1){ 
        while(s[j]==t[j] && j>=0){
            s[j] = '_'; t[j]='_';
            j--;
        }
        if(j<0){
            break;
        }
        string p = "";
        if(s[0]==t[j]){
            v.pb(1); v.pb(j+1);
            for(int i=j;i>=1;i--){
                if(s[i]=='1'){
                    p+='0';
                }
                else{
                    p+='1';
                }
            }
            p+=s[0];
            for(int i=j+1;i<n;i++){
                p+='_';
            }
        }
        else{
            v.pb(j+1);
            for(int i=j;i>=0;i--){
                if(s[i]=='1'){
                    p+='0';
                }
                else{
                    p+='1';
                }
            }
            for(int i=j+1;i<n;i++){
                p+='_';
            }
        }
        s = p;
        // cout << j << " " << s << " " << t << endl;
        if(s==t){
            break;
        }
    }
    cout << v.size() << " ";
    for(auto x:v){
        cout << x << " ";
    }nl;
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

