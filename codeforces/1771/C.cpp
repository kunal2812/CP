#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

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
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef map<int,int> mii;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os; // find_by_order, order_of_key (#less than key)
typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> oms; // ordered_multiset
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

#define scn(x) cin >> x
#define scna(a) for(int i=0; i<n; i++){cin >> a[i];}
#define pr(x) cout << x << endl
#define pra(a) for(auto x:a){cout << x << " ";}nl

ll mod = 1000000007;

/*
- Ignore a[i]=1
- Check if some numbers are equal
- prime factorize number and check if the number is divisible by some prime > 32000 and store it into set too
- Check if the prime you are getting after dividing a num is present in the array or not
*/
vi primes;
void sieve(int n){
    vector<bool> chk(n+1,true);
    for(int i=2; i*i<=n; i++){
        if(chk[i]){
            for(int j=2*i; j<=n; j+=i){
                chk[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(chk[i]){
            primes.pb(i);
        }
    }
}
void solve(int xx){ 
    int n; cin >> n;
    vi a(n);
    set<int> f;
    bool chk = false;
    fr(i,0,n,1){
        cin >> a[i];
        if(a[i]==1){
            continue;
        }
        if(f.find(a[i])!=f.end()){
            chk = true;
        }
        f.insert(a[i]);
    }
    if(chk){
        yes;
    }
    set<int> s;
    for(auto x:primes){
        int ok = 0;
        fr(i,0,n,1){
            if(a[i]==1){
                continue;
            }
            if((a[i]%x)==0){
                if(s.find(a[i]/x)!=s.end()){
                    yes;
                }
                else{
                    ok++;
                }
                int jj = a[i];
                while(jj%x==0){
                    jj/=x;
                }
                if(jj>32000){
                    if(s.find(jj)!=s.end()){
                        yes;
                    }
                    if(f.find(jj)!=f.end() && a[i]!=jj){
                        yes;
                    }
                    s.insert(jj);
                }
            }
        }
        if(ok>=2){
            yes;
        }
    }no;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0;
    sieve(32000);
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
