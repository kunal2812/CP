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
6 5 4 3 2
1 5 4 3 2
1 1 4 3 2
1 1 1 3 2

*/
struct op{
    int x,y,z;
};
void solve(int xx){ 
    int n; cin >> n;
    vi a(n);
    fr(i,0,n,1){
        cin >> a[i];
    }
    if(a[n-2]>a[n-1]){
        pr(-1); return;
    }
    bool ok = true;
    fr(i,0,n-1,1){
        if(a[i]>a[i+1]){
            ok = false;
            break;
        }
    }
    if(ok){
        pr(0); return;
    }
    vector<op> ops; bool f = false;
    fr(i,0,n-2,1){
        a[i] = a[n-2]-a[n-1];
        op op; op.x = i, op.y = n-2, op.z = n-1;
        ops.pb(op);
    }
    ok = true;
    fr(i,0,n-1,1){
        if(a[i]>a[i+1]){
            ok = false;
            break;
        }
    }
    if(!ok){
        pr(-1); return;
    }
    cout << ops.size() << endl;
    for(auto x:ops){
        cout << x.x+1 << " " << x.y+1 << " " << x.z+1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
