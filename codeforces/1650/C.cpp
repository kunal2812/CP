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
    int n,m; cin >> n >> m;
    map<pii, int> s,s1; int x,w;
    fr(i,0,m,1){
        cin >> x >> w;
        s[{w,x}] = i+1;s1[{w,x}] = i+1;
    }
    set<pii> valid;
    fr(i,0,2*n,1){
        valid.insert({s.begin()->ff.sc, s.begin()->ff.ff});
        s.erase(s.begin());
    }
    list<pii> t;
    for(auto x:valid){
        t.pb(x);
    }
    ll ans = 0;
    vector<pii> co;
    while(!t.empty()){
        pii b = t.front(); t.ppf();
        pii e = t.back(); t.ppb();
        ans += (ll)((ll)b.sc+e.sc);
        co.pb({s1[{b.sc,b.ff}], s1[{e.sc,e.ff}]});
    }
    pr(ans);
    for(auto x:co){
        cout << x.ff << " " << x.sc << endl;
    }nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
