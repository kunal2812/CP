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

bool increasing(vi &a){
    fr(i,0,sz(a)-1,1){
        if(a[i]>=a[i+1]){
            return false;
        }
    }
    return true;
}

void solve(int xx){ 
    int n; cin >> n;
    vi a(n);
    fr(i,0,n,1){
        cin >> a[i]; 
    }
    if(n==1){
        pr(0); return;
    }
    ll ans = 0;
    while(!increasing(a)){
        fr(i,1,n,1){
            if(i!=1 && a[i-1]==0 && a[i]==1){
                pr(-1); return;
            }
            if(a[i-1]==0 && a[i]==0){
                pr(-1); return;
            }
            while(a[i-1]>=a[i] && a[i-1]>0){
                a[i-1]/=2; ans++;
            }
        }
        // for(auto x:a){
        //     cout << x << " ";
        // }nl;
    }
    pr(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
