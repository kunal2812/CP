#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ld long double
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os; // find_by_order, order_of_key
typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> oms; // ordered_multiset
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

long double meet(long double m, vi a, vi b){
    ld l = a[0]-(m-b[0]), r = a[0]+(m-b[0]);
    fr(i,1,sz(a),1){
        ld l1 = a[i]-(m-b[i]), r1 = a[i]+(m-b[i]);
        if(r<l1 || l>r1){
            return -1;
        }
        l = max(l,l1), r = min(r, r1);
    }
    return (l+r)/2;
}

void solve(int xx){ 
    int n; cin >> n;
    vi a(n), b(n);
    fr(i,0,n,1) cin >> a[i];
    fr(i,0,n,1) cin >> b[i];
    long double l = 0, r = 2e8, ans; 
    while(abs(l-r)>1e7){
        long double m = (l+r)/2;
        ld pp = meet(m, a, b);
        if(pp!=-1){
            ans = pp;
            r = m;
        }
        else{
            l = m;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
