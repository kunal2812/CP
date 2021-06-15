#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl;


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
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

ll mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

ll a[100005];
umii m;
ll dp[100005];

void Solution(){
    int n;
    cin >> n;
    ll maxm = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
        maxm = max(maxm, a[i]);
    }
    vi v;
    for(auto x:m){
        v.pb(x.first);
    }
    ll ans=0;
    dp[0] = 0;
    dp[1] = m[1];
    for(int i=2;i<=maxm;i++){
        dp[i] = max((ll)(dp[i-2] + (ll)i*m[i]), dp[i-1]);
        // cout << dp[i] << " ";
    }
    // nl;
    cout << dp[maxm] << endl;
}

int main() {
    fast;
        Solution();
    return 0;
}

