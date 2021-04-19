#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define  IN for(int i=1;i<=n;i++){cin >> a[i];}
#define  OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, vi> umiv;
typedef unordered_map<int, int> umii;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }
ll exponentiation(ll base,
                        ll exp)
{
    if (exp == 0)
        return 1;
  
    if (exp == 1)
        return base % mod;
  
    ll t = exponentiation(base, exp / 2);
    t = (t * t) % mod;
  
    // if exponent is even value
    if (exp % 2 == 0)
        return t;
  
    // if exponent is odd value
    else
        return ((base % mod) * t) % mod;
}
void Solution(){
    int n,k;
    cin >> n >> k;
    cout << exponentiation(n,k) << endl;
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

