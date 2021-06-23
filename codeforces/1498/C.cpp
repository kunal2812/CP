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
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

ll mod = 1000000007;



void Solution(){
    int n ,k;
    cin >> n >> k;
    if(n==1){
        cout << min(k,2) << endl; return;
    }
    if(k==1){
        cout << 1 << endl; return;
    }
    if(k==2){
        cout << 1+n << endl; return;
    }
    ll ans = 1+n;
    vll v(n+5,0);
    k=k-2;
    if(k==0){
        cout << ans << endl; return;
    }
    for(int i=1;i<n;i++){
        v[i] = i;
    }
    int i=0;
    while(k>=1){
        if(i%2==1){
            // cout << v[1] << " ";
            for(int i=2;i<=(n-1);i++){
                v[i] = v[i-1]+v[i];
                // cout << v[i] << " ";
                v[i]%=mod;
            }
            // nl;
            // cout << v[n-1] << endl;
            ans+=v[n-1];
            ans%=mod;
        }
        else{
            // cout << v[n-1] << " ";
            for(int i=n-2;i>=1;i--){
                v[i] = v[i+1]+v[i];
                // cout << v[i] << " ";
                v[i]%=mod;
            }
            // nl;
            // cout << v[1] << endl;
            ans+=v[1];
            ans%=mod;
        }
        k--;
        i++;
    }
    ans%=mod;
    cout << ans << endl;
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

