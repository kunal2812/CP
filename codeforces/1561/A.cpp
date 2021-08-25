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

bool isSorted(vi &a, int n){
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            return false;
        }
    }
    return true;
}
void Solution(){ 
    int n; cin >> n; vi a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int i;
    for(i=1;i<=n;i++){
        if(isSorted(a,n)){
            cout << i-1 << endl; return;
        }
        if(i%2==1){
            for(int j=1;j<=(n-2);j+=2){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                }
            }
        }
        else{
            for(int j=2;j<=(n-1);j+=2){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout << a[i] << " ";
        // }nl;
    }        
    if(isSorted(a,n)){
        cout << i-1 << endl; return;
    }
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

