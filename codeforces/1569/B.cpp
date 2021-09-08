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

ll mod = 1000000007;

bool ex[52];
void Solution(int x){ 
    int n; cin >> n; string s; cin >> s;
    for(int i=0;i<n;i++){
        ex[i] = false;
    }
    vector<string> v;
    for(int i=0;i<n;i++){
        string t = "";
        for(int j=0;j<n;j++){
            t+='_';
        }
        v.pb(t);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='_'){
                if(i==j){
                    v[i][j]='X';
                }
                else if(s[j]==s[i] && s[j]=='1'){
                    v[i][j]='=';
                    v[j][i]='=';
                }
                else if(s[i]=='1'){
                    v[i][j]='+';
                    v[j][i]='-';
                }
                else if(s[i]=='2' && s[j]=='2' && ex[i]==false){
                    v[i][j]='+';
                    v[j][i]='-';
                    ex[i] = true;
                }
                else if(s[j]=='2' && s[i]=='2' && ex[j]==false){
                    v[i][j]='-';
                    v[j][i]='+';
                    ex[j] = true;
                }
                else{
                    v[i][j]='=';
                    v[j][i]='=';
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            for(int j=0;j<n;j++){
                if(v[i][j]=='-'){
                    no;
                }
            }
        }
        else{
            if(ex[i]==false){
                no;
            }
        }
    }
    pr("YES");
    for(auto x:v){
        cout << x << endl;
    }
}

int main() {
    fast;
    int T;
    cin >> T;
    int i=0;
    while(T!=0){
        Solution(++i);
        T--;
    }
    return 0;
}
