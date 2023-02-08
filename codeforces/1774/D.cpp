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
void solve(int xx){ 
    int n,m; cin >> n >> m;
    vvi a(n,vi(m));
    fr(i,0,n,1){
        fr(j,0,m,1){
            cin >> a[i][j];
        }
    }
    ll cnt = 0;
    fr(i,0,n,1){
        cnt+=count(all(a[i]),1);
    }
    if(cnt%n){
        pr(-1); return;
    }
    cnt/=n;
    vector<set<int>> vv(n);
    set<int> extra, deficit;
    ll ans = 0;
    fr(i,0,n,1){
        int t = count(all(a[i]),1);
        if(t>cnt){
            extra.insert(i);
            ans+=(t-cnt);
            fr(j,0,m,1){
                if(a[i][j]==1){
                    vv[i].insert(j);
                }
            }
        }
        else if(t<cnt){
            deficit.insert(i);
            fr(j,0,m,1){
                if(a[i][j]==0){
                    vv[i].insert(j);
                }
            }
        }
    }
    pr(ans);
    while(!extra.empty()){
        int i1 = *extra.begin();
        int i2 = *deficit.begin();
        int pp = vv[i1].size();
        int kk = vv[i2].size();
        kk = m-kk;
        // cout << i1 << " " << i2 << " " << pp << " " << kk << endl;
        vi del;
        for(auto x:vv[i1]){
            if(vv[i2].find(x)!=vv[i2].end()){
                cout << i1+1 << " " << i2+1 << " " << x+1 << endl;
                del.pb(x);
                pp--;kk++;
            }
            if(pp==cnt || kk==cnt){
                break;
            }
        }
        if(pp==cnt){
            extra.erase(i1);
        }
        if(kk==cnt){
            deficit.erase(i2);
        }
        for(auto x:del){
            vv[i2].erase(x);
            vv[i1].erase(x);
        }
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
