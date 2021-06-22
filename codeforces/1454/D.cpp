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
map<ll, int> primeFactors(ll n)
{
    map<ll, int> s;
    while (n % 2 == 0)
    {
        s[2]++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s[i]++;
            n = n/i;
        }
    }
    if (n > 2)
        s[n]++;
        
    return s;
}
void Solution(){
    ll n;
    cin >> n;
    map<ll, int> m =  primeFactors(n);
    if(m.size()==1){
        for(auto x:m){
            int t = x.sc;
            cout << t << endl;
            while(t--){
                cout << x.ff << " ";
            }
        }
        nl;
        return;
    }
    ll kk = 0;
    for(auto x:m){
        int t = x.sc;
        kk = max(kk, (ll)t);
    }
    cout << kk << endl;
    vll v;
    for(auto x:m){
        int t = x.sc;
        while(t--){
            ll pr=x.ff;
            m[x.ff]--;
            for(auto y:m){
                if(x.ff!=y.ff && y.sc>0){
                    pr*=y.ff;
                    m[y.ff]--;
                }
            }
            v.pb(pr);
        }
    }
    sort(v.begin(), v.end());
    for(auto x: v){
        cout << x << " ";
    }
    nl;
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

