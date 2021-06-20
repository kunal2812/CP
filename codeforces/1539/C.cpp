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
ll a[200005];
void Solution(){
    ll n,k,x;
    cin >> n >> k >> x;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ll diff[200005];
    ll ct=0;
    vll v;
    for(int i=2;i<=n;i++){
        diff[i] = abs(a[i]-a[i-1]);
        if(diff[i]>x){
            v.pb(diff[i]);
            ct++;
        }
    }
    ++ct;
    ll gg=0;
    vll kk;
    for(int i=0;i<v.size();i++){
        ll t = ceil((dc)v[i]/x);
        kk.pb(t-1);
    }
    sort(kk.begin(), kk.end());
    int i=0;
    while((k-kk[i])>=0 && i<kk.size()){
        ct--;
        k-=kk[i];
        i++;
    }
    cout << (ct) << endl;
}

int main() {
    fast;
    // int T;
    // cin >> T;
    // while(T!=0){
        Solution();
    //     T--;
    // }
    return 0;
}

