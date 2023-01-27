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

bool isSatisfy(vi &x, vi &y){
    set<int> s;  int t = -1;
    for(auto x:y){
        s.insert(x);
    }
    fr(i,1,sz(x)+1,1){
        if(s.find(i)==s.end()){
            t = i;
        }
    }
    int i=0,j=0;
    while(i<sz(x) && j<sz(y)){
        if(x[i]==t){
            i++;
        }
        else if(x[i]!=y[j]){
            return false;
        }
        else{
            i++;
            j++;
        }
    }
    return true;
}


void solve(int xx){ 
    int n; cin >> n;
    vvi a(n,vi(n));
    vi ans(n);
    set<int> s;
    fr(i,0,n,1){
        fr(j,0,n-1,1){
            cin >> a[i][j];
            if(i==0){
                ans[j] = a[i][j];
                s.insert(ans[j]);
            }
        }
    }
    vvi all;
    fr(i,1,n+1,1){
        if(s.find(i)==s.end()){
            ans[n-1] = i;
        }
    }
    all.pb(ans);
    // for(auto x:ans){
    //     cout << x << " ";
    // }nl;
    fr(i,0,n,1){
        vi tmp;
        fr(j,0,n-1,1){
            if(i==j){
                tmp.pb(ans[n-1]);
                tmp.pb(ans[j]);
            }
            else{
                tmp.pb(ans[j]);
            }
        }
        all.pb(tmp);
    }
    // for(auto x:all){
    //     for(auto y:x){
    //         cout << y << " ";
    //     }nl;
    // }
    vector<bool> is(all.size(),true);
    fr(t,0,sz(all),1){
        if(is[t]){
            fr(i,0,n,1){
                if(!isSatisfy(all[t],a[i])){
                    is[t] = false;
                }
            }
        }
    }
    fr(i,0,sz(all),1){
        if(is[i]){
            for(auto x:all[i]){
                cout << x << " ";
            }nl; return;
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
