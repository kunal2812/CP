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


int arr[100005][26];
void Solution(){ 
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<26;j++){
            arr[i][j] = 0;
        }
    }
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int j=1;j<n;j++){
        string s;
        cin >> s;
        for(int i=0;i<s.length();i++){
            arr[i][s[i]-97]++;
        }
    }
    vi ct(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int ch = v[j][i]-97;
            arr[i][ch]--;
            if(arr[i][ch]<0){
                ct[j]++;
            }
        }
    }
    string ans = "";
    for(int i=0;i<m;i++){
        for(int j=0;j<26;j++){
            if(arr[i][j]<0){
                ans+=char(j+97);
            }
        }
    }
    cout << ans << endl; cout.flush(); return;
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

