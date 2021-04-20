#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define  IN for(int i=0;i<n;i++){cin >> a[i];}
#define  OUT for(int i=0;i<n;i++){cout << a[i] << " ";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

ll getMin(ll arr[], int n)
{
    ll res = arr[0];
    for (int i = 1; i < n; i++)
        res = min(res, arr[i]);
    return res;
}

void Solution(){
    int n;
    cin >> n;
    ll a[200005];
    IN;
    ll t = getMin(a,n);
    for(int i=0;i<n;i++){
        if((t&a[i])!=t){
            // cout << a[i] << " " << t << " ai" << endl;
            cout << 0 << endl;
            return;
        }
    }
    ll ct=0;
    for(int i=0;i<n;i++){
        if(a[i]==t){
            ct++;
        }
    }
    ll fact = 1;
    for(int i=2;i<=(n-2);i++) fact = ((fact%mod) * (i%mod))%mod;
    ll ans = (ll)(((ct*(ct-1))%mod) * (fact%mod) % mod);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

