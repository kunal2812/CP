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
4
3 13
0 1 2

1 10 100

2 777
0 4

3 255
0 1 3



1 10 1000
255 2550 255000


2

10 1000000000
0 1 2 3 4 5 6 7 8 9
*/

ll power(ll x, int y){
    ll ans = 1;
    while(y){
        if(y&1){
            ans = ans*x;
        }
        x = x*x;
        y/=2;
    }
    return ans;
}

void solve(int xx){ 
    ll n,k; cin >> n >> k;
    vll a(n);
    k++;
    fr(i,0,n,1){
        cin >> a[i]; a[i] = power(10, a[i]);
    }
    ll curr = 0;
    fr(i,0,n-1,1){
        int notes = min(k,(a[i+1]-a[i])/a[i]);
        k-=notes;
        curr+=((ll)notes*a[i]);
        // cout << notes << " " << k << " " << curr << endl;
    }
    if(k>0){
        curr+=(ll)(a[n-1]*k);
    }
    pr(curr);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
