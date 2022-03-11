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
6
7 3
10 2 1 3 1 19 3

3 5
2 4 6 7

i = 2 k = 1 
i = 3 k = 1

3 2
1 13 1

1 3
2

0

9 3
2 4 2 1 1 1 1 4 2

4 5 6 7
1 3 9

1,1
1,2
3,1
6,1


3 1
1 1 1
4 1
1 2 1 1
2 2
1 2
*/

bool prms[1000001];
set<int> pr;

void sieve(int n = 1e6){
    fr(i,1,n + 1, 1){
        prms[i] = true;
    }
    for(int i=2; i*i<=n; i++){
        if(prms[i]){
            for(int j = i*i; j<=n; j+=i){
                prms[j] = false;
            }
        }
    }
    fr(i,2,n+1,1){
        if(prms[i]){
            // cout << i << endl;
            pr.insert(i);
        }
    }
}


bool isPrime(ll x){
    if(pr.find(x)!=pr.end()){
        return true;
    }
    return false;
}

void solve(int xx){ 
    ll n,e; cin >> n >> e;
    vll a(n+1);
    set<int> ones, primes;
    fr(i,1,n+1,1){
        cin >> a[i];
        if(a[i]==1){
            ones.insert(i);
        }
        else if(isPrime(a[i])){
            primes.insert(i);
        }
    }
    if(sz(primes)==0){
        pr(0); return;
    }
    
    ll ans = 0;
    // for(auto i:ones){
    //     int k=1; int p = 0;
    //     while((i+k*e)<=n){
    //         if(primes.find(i+k*e)!=primes.end()){
    //             k++; p++;
    //         }
    //         else if(ones.find(i+k*e)!=ones.end()){
    //             k++;
    //         }
    //         else{
    //             break;
    //         }
    //         if(p==1){
    //             ans++;
    //         }
    //         if(p>1){
    //             break;
    //         }
    //     }
    // }
    for(auto i:primes){
        int k=1; int p = 1;
        ll t1 = 0, t2 = 0;
        while((i+k*e)<=n){
            if(primes.find(i+k*e)!=primes.end()){
                k++; p++;
            }
            else if(ones.find(i+k*e)!=ones.end()){
                k++;
            }
            else{
                break;
            }
            if(p==1){
                t1++;
            }
            if(p>1){
                break;
            }
        }
        ans+=(ll)t1;
        k=1; p = 1;
        while((i-k*e)>0){
            if(primes.find(i-k*e)!=primes.end()){
                k++; p++;
            }
            else if(ones.find(i-k*e)!=ones.end()){
                k++;
            }
            else{
                break;
            }
            if(p==1){
                t2++;
                t2+=(ll)t1;
            }
            if(p>1){
                break;
            }
        }
        ans+=(ll)t2;
        // cout << t1 << " " << t2 << endl;
    }
    pr(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
