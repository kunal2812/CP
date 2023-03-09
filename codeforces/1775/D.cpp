/*
References: 

*/
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
typedef vector<vll> vvll;
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

int par[300005];
vi g[300005];
unordered_set<int> primes;
void sieve(int n){
    vector<bool> chk(n+1,true);
    for(int i=2; i*i<=n; i++){
        if(chk[i]){
            for(int j=2*i;j<=n; j+=i){
                chk[j] = false;
            }
        }
    }
    fr(i,2,n+1,1){
        if(chk[i]){
            primes.insert(i);
        }
    }
}
void solve(int xx){ 
    int n; cin >> n;
    vi a(n);
    mii m;
    fr(i,0,n,1){
        cin >> a[i];
        if(m.find(a[i])==m.end()){
            for(int j=2;(j*j)<=a[i]; j++){
                if((a[i]%j)==0){
                    // cout << a[i] << " " << j << endl;
                    // cout << a[i]/j << " " << a[i] << endl;
                    g[a[i]].pb(j);
                    g[j].pb(a[i]);
                    g[a[i]].pb(a[i]/j);
                    g[a[i]/j].pb(a[i]);
                }
            }
        }
        m[a[i]] = i+1;
    }
    int src, dest;
    int s,t; cin >> s >> t;
    src = s, dest = t;
    // To prevent overwriting of most important value that we need
    m[a[s-1]] = s;
    m[a[t-1]] = t;
    s = a[s-1];
    t = a[t-1];
    // If src and destination indices are same
    if(src==dest){
        cout << 1 << " " << src << endl; return;
    }
    // If either src value or dest value is 1 then communication not possible since gcd = 1
    if(s==1 || t==1){
        pr(-1);
        return;
    }
    // If indices are not same but values between 2 nodes are same
    if(s==t){
        cout << 2 << " " << src << " " << dest << endl; return;
    }
    queue<int> q; q.push(s); par[s] = -1;
    bool ok = false;
    while(!q.empty()){
        int f = q.front(); q.pop();
        // cout << f << " ";
        if(f==t){
            ok = true;
            break;
        }
        for(auto u:g[f]){
            if(par[u]==0){
                par[u] = f;
                q.push(u);
            }
        }
    }
    if(!ok){
        pr(-1); return;
    }
    vi ans;
    ans.pb(t);
    t = par[t];
    while(t!=-1){
        // Skip only primes
        if(primes.find(t)==primes.end() || t==s){
            ans.pb(t);
        }
        t = par[t];
    }
    pr(sz(ans));
    rev(ans);
    for(auto x:ans){
        cout << m[x] << " ";
    }nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0;
    sieve(300005);
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
// kunal0403