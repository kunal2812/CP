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

ll mod = 1000000007;

/*

*/
#define N 1e6

vll primes;

void sieve(){
    bool prime[1000006];
    fr(i,2,N+1,1){
        prime[i] = true;
    }
    for(int j=2; j*j<=N; j++){
        if(prime[j]){
            fr(k,j*j,N+1,j){
                prime[k] = false;
            }
        }
    }
    fr(i,2,N+1,1){
        if(prime[i]){
            primes.pb(i);
        }
    }
}

ll f(ll p, ll q){
    double res = q*q*q; res*=p;
    if(res>2e18){
        return 4e18;
    }
    return p*q*q*q;
}

void solve(int xx){ 
    ll s; cin >> s;
    int ind;
    fr(i,0,sz(primes),1){
        ll x = primes[i];
        ll ttt = (ll)2*x*x*x;
        if(ttt>s){
            break;
        }
        ind = i;
    }
    // cout << primes[ind] << endl;
    ll ans = 0;
    fr(i,0,ind+1,1){
        int l = 0, r = i-1;
        while(l<r){
            int mid = (l+r+1)/2;
            if(f(primes[mid], primes[i])>s){
                r = mid-1;
            }
            else{
                l = mid;
            }
        }
        ans+=(l+1);
    }
    cout << ans-1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    sieve();
    // cout << primes.size() << endl;
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
