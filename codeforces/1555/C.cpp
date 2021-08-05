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


void Solution(){ 
    int m; cin >> m;
    vector<vi> v(2,vi(m,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    ll kk = LONG_LONG_MAX;
    v[0][0] = 0; v[1][m-1] = 0;
    
    vector<vll> pref(2,vll(m,0));
    
    pref[0][m-1] = v[0][m-1]; pref[1][0] = v[1][0];
    
    for(int i=m-2;i>=1;i--){
        pref[0][i] = pref[0][i+1] + v[0][i];
    }
    for(int i=1;i<(m-1);i++){
        pref[1][i] = pref[1][i-1] + v[1][i];
    }
    // for(int i=0;i<m;i++){
    //     cout << pref[0][i] << " ";
    // }nl;
    // for(int i=0;i<m;i++){
    //     cout << pref[1][i] << " ";
    // }nl;
    int j;
    int ind = 0;
    for(j=0;j<m;j++){
        // cout << j << " " << kk << " " << pref[0][j+1] <<  " " << pref[1][j-1] << endl;
        if((j-1)>=0 && (j+1)<m){
            kk = min(kk, max(pref[0][j+1],pref[1][j-1])); ind=j;
        }
        else if(j==0 && (j+1)<m){
            kk = min(kk, pref[0][j+1]); ind=j;
        }
        else if(j==(m-1) && (j-1)>=0){
            kk = min(kk, pref[1][j-1]); ind=j;
        }
        // cout << j << " " << kk << endl;
    }
    if(kk==LONG_LONG_MAX){
        kk=0;
    }
    cout << kk << endl;
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

