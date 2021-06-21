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

ll dp[2200];
void init(){
    for(int i=1;i<=2000;i++){
        dp[i] = i*(i+1);
        dp[i]/=2;
    }
}
void Solution(){
    int x;
    cin >> x;
    int l=1;
    int r=2000; int mid;
    ll ans=-1;
    while(l<=r){
        mid = (l+r)/2;
        if(dp[mid]<x){
            l = mid+1;
        }
        else{
            ans = mid;
            r=mid-1;
        }
    }
    int diff = dp[ans]-x;
    if(diff==1){
        cout << ans+1 << endl; return;
    }
    else{
        cout << ans << endl;
    }
}

int main() {
    fast;
    int T;
    init();
    cin >> T;
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

