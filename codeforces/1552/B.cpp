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

void Solution(){ 
    int n; cin >> n;
    vector<vi> v(n,vi(5,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin >> v[i][j];
        }
    }
    if(n==1){
        cout << 1 << endl; return;
    }
    int i=0;int j=n-1;
    int win = -1;
    while(i<j && i>=0 && j<=(n-1)){
        int ct=0;
        for(int t=0;t<5;t++){
            if(v[i][t]>v[j][t]){
                ct++;
            }
        }
        if(ct>=3){
            win = j;
            i++;
        }
        else{
            win = i;
            j--;
        }
    }
    for(int i=0;i<n;i++){
        int ct=0;
        if(i==win){
            continue;
        }
        else{
            for(int t=0;t<5;t++){
                if(v[win][t]<v[i][t]){
                    ct++;
                }
            }
            if(ct<3){
                cout << -1 << endl; return;
            }
        }
    }
    cout << win+1 << endl;
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

