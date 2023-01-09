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
typedef pair<ll, ll> pll;

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

ll m1 = 1e9+7, m2 = 1500450271;

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
    return p;
}
ll power31[2000005];
ll power111[2000005];
void init(){
    power31[0] = power111[0] = 1;
    fr(i,1,2000001,1){
        power31[i] = (ll)(power31[i-1]*31)%m1;
        power111[i] = (ll)(power111[i-1]*111)%m2;
    }
}
void solve(int xx){ 
    int n; cin >> n;
    string s; cin >> s;
    vector<pll> hash1(2*n+1,{0,0});
    vector<pll> hash2(2*n+1,{0,0});
    ll p1 = 31, p2 = 111;
    ll m1 = 1e9+7, m2 = 1500450271;
    ll h1 = 0, h2 = 0;
    fr(i,0,2*n,1){
        h1+=((s[i]-'a'+1)*p1); p1*=31; p1%=m1; h1%=m1;
        h2+=((s[i]-'a'+1)*p2); p2*=111; p2%=m2; h2%=m2;
        hash1[i+1] = {h1,h2};
    }
    p1 = 31, p2 = 111;
    h1 = 0, h2 = 0;
    rfr(i,2*n-1,0,1){
        h1+=((s[i]-'a'+1)*p1); p1*=31; p1%=m1; h1%=m1;
        h2+=((s[i]-'a'+1)*p2); p2*=111; p2%=m2; h2%=m2;
        hash2[i+1] = {h1,h2};
    }
    pll t1,t2,t3,t4;
    fr(i,0,n+1,1){
        t1 = hash1[i];
        t2.ff = inv(hash1[2*n].ff-hash1[n+i].ff+m1, power31[n+i], m1);
        t2.sc = inv(hash1[2*n].sc-hash1[n+i].sc+m2, power111[n+i], m2);
        t3.ff = inv(hash2[n+1].ff-hash2[n+1+i].ff+m1, power31[n-i], m1);
        t3.sc = inv(hash2[n+1].sc-hash2[n+1+i].sc+m2, power111[n-i], m2);
        t4.ff = inv(hash2[i+1].ff-hash2[1+n].ff+m1, power31[n], m1);
        t4.sc = inv(hash2[i+1].sc-hash2[1+n].sc+m2, power111[n], m2);
        // cout << i << " " << 0 << " " << 0 << " " << t1.ff << " " << t1.sc << endl;
        // cout << 2*n << " " << n+i << " " << n+i << " " << t2.ff << " " << t2.sc <<endl;
        // cout << n+1 << " " << n+i+1 << " " << n-i << " " << t3.ff << " " << t3.sc <<endl;
        // cout << i+1 << " " << n+1 << " " << n << " " << t4.ff << " " << t4.sc <<endl;
        // nl;nl;
        if(t1==t3 && t2==t4){
            string ans = s.substr(i,n);
            rev(ans);
            cout << ans << " " << i << endl; return;
        }
    }
    pr(-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    init();
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
