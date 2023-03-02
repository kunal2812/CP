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
    return p%mod;
}

ll power(ll p, ll q, ll mod){
    ll ans = 1;
    while(q){
        if(q&1){
            ans = (ll)(ans%mod)*(p%mod); ans%=mod;
        }
        p = (ll)(p%mod)*(p%mod); p%=mod;
       q/=2;
    }
    return ans%mod;
}

void solve(int xx){ 
    int n; cin >> n;
    string s; cin >> s;
    set<pll> st;
    ll p1 = 31, p2 = 111;
    ll m1 = 1000000007, m2 = 998244353;
    ll h1, h2;
    p1 = 31; p2 = 111;
    h1 = 0; h2 = 0;
    for(int i=0; i<n; i++){
        h1+=((s[i]-'a'+1)*p1); p1*=31; p1%=m1; h1%=m1;
        h2+=((s[i]-'a'+1)*p2); p2*=111; p2%=m2; h2%=m2;
    }
    // cout << h1 << " " << h2 << endl;
    p1 = 31; p2 = 111;
    ll h3 = 0, h4 = 0;
    fr(i,0,n-1,1){
        // left part = h3, h4
        // mid part = t1, t2
        // right part = h1, h2 - 
        // cout << i << " " << h3 << " " << h4 << endl;
        ll t1 = 0, t2 = 0;
        
        ll q1 = power(31,i+1,m1);
        ll q2 = power(111,i+1,m2);
        
        t1+=((s[i]-'a'+1)*q1);  t1%=m1;
        t2+=((s[i]-'a'+1)*q2); t2%=m2;
        q1*=31; q2*=111; q1%=m1, q2%=m2;
        t1+=((s[i+1]-'a'+1)*q1); t1%=m1;
        t2+=((s[i+1]-'a'+1)*q2); t2%=m2;
        
        // cout << t1 << " " << t2 << endl;
        
        ll jj = h1-(h3+t1)%m1+m1; jj%=m1;
        ll kk = h2-(h4+t2)%m2+m2; kk%=m2;
        
        jj = inv(jj,power(31,2,m1),m1);
        kk = inv(kk,power(111,2,m2),m2);
        
        jj+=h3; jj%=m1;
        kk+=h4; kk%=m2;
        
        // cout << jj << " " << kk << endl;
        
        st.insert({jj,kk});
        
        h3+=((s[i]-'a'+1)*p1); p1*=31; p1%=m1; h3%=m1;
        h4+=((s[i]-'a'+1)*p2); p2*=111; p2%=m2; h4%=m2;
    }
    pr(sz(st));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
