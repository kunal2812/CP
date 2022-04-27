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
void solve(int xx){ 
    int n; cin >> n;
    vi a(n);
    fr(i,0,n,1){
        cin >> a[i];
    }
    int i = 0, j = n-1;
    int ans = 0; ll w1 = 0, w2 = 0;
    while(i<j){
        w1+=a[i]; i++;
        while(j>=i && (w2+a[j])<=w1){
            w2+=a[j]; j--;
        }
        if(w1==w2){
            ans = max(ans, i+n-j-1);
        }
        // cout << w1 << " " << w2 << " " << i << " " << j << endl;
    }
    w1 = 0, w2 = 0;
    while(i<j){
        w2+=a[j]; j--;
        while(j>=i && (w1+a[i])<=w2){
            w1+=a[i]; i++;
        }
        if(w1==w2){
            ans = max(ans, i+n-j-1);
        }
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
