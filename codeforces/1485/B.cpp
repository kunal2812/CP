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

void Solution(){
    int n,q,k;
    ll a[100005];
    cin >> n >> q >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n==1){
        while(q--){
            int l,r;
            cin >> l >> r;
            cout << k-1 << endl;
        }
        return;
    }
    vll dp(n+2,0);
    dp[0] = 0;
    dp[1] += a[2]-1;
    dp[n] = k - a[n-1];
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1]+(a[i+1]-a[i-1]-1);
    }
    dp[n]+=dp[n-1];
    while(q--){
        int l,r;
        cin >> l >> r;
        int op = r-l+1;
        if(op==1){
            cout << k-1 << endl;
        }
        else{
            ll ans = 0;
            ans += (a[l+1]-1);
            ans += (k - a[r-1]);
            if(op==2){
                cout << ans-op << endl; continue;
            }
            ans += (dp[r-1] - dp[l]);
            ans-=op;
            cout << ans << endl;
        }
    }
}

int main() {
    fast;
    Solution();
    return 0;
}

