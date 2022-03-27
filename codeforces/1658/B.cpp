#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front

#define yes cout << "YES" << endl; return
#define no  cout << "NO" << endl; return

#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 998244353;

/*

*/

/*
Source: https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/
*/


ll inv(ll p, ll q, ll mod){
    ll expo = mod-2;
    while(expo){
        if(expo&1){
            p = (ll)(p%mod)*(q%mod); p%=mod;
        }
        q = (ll)(q%mod)*(q%mod); q%=mod;
        expo/=2;
    }
    return p;
}

unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long ncr(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

ll fact(ll n){
    ll ans = 1;
    fr(i,1,n+1,1){
        ans = (ll)(ans%mod)*(i%mod);
        ans%=mod;
    }
    return ans;
}

void solve(int xx){ 
    ll n; cin >> n;
    if(n%2){
        pr(0); return;
    }
    else{
        cout << inv(fact(n),ncr(n,n/2,998244353),998244353) << endl;
    }
    // fr(i,1,12,1){
    //     vi arr(i);
    //     iota(all(arr),1);
    //     int ans = 0;
    //     do {
    //         int curr_gcd = 0;
    //         fr(j,0,i,1){
    //             curr_gcd = __gcd(curr_gcd, (j+1)*arr[j]);
    //         }
    //         if(curr_gcd>1){
    //             // for(auto x:arr){
    //             //     cout << x << " ";
    //             // }nl;
    //             ans++;
    //         }
    //     } while (next_permutation(all(arr)));
    //     cout << i << " " << ans << endl;
    // }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
