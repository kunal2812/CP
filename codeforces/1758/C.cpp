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
#define scna(x,a,b) for(int i=a; i<=b; i++){cin >> x[i];}
#define pr(x) cout << x << endl
#define pra(a) for(auto x:a){cout << x << " ";}nl

ll mod = 1000000007;

/*

*/
void solve(int xx){ 
    int n,x; cin >> n >> x;
    vi ans(n+1,-1);
    ans[1] = x;
    ans[n] = 1;
    map<int,set<int>> m;
    vector<set<int>> choices(n);
    vector<bool> used(n+1,false);
    used[x] = used[1] = true;
    fr(i,2,n,1){
        fr(j,i,n+1,i){
            if(!used[j]){
                choices[i].insert(j);
            }
        }
        if(sz(choices[i])==1){
            ans[i] = *choices[i].begin();
            used[ans[i]] = true;
            choices[i].clear();
        }
        else{
            m[sz(choices[i])].insert(i);
        }
    }
    fr(i,2,n+1,1){
        if(m[i].empty()){
            continue;
        }
        for(auto y:m[i]){
            vi del;
            for(auto z:choices[y]){
                if(used[z]){
                    del.pb(z);
                }
            }
            for(auto z:del){
                choices[y].erase(z);
            }
            if(sz(choices[y])==1){
                ans[y] = *choices[y].begin();
                used[ans[y]] = true;
                choices[y].clear();
            }
            else{
                if(m[sz(choices[y])].find(y)==m[sz(choices[y])].end()){
                    m[sz(choices[y])].insert(y);
                }
            }
        }
    }
    fr(i,1,n+1,1){
        if(ans[i]==-1){
            for(auto x:choices[i]){
                if(used[x]){
                    continue;
                }
                else{
                    ans[i] = x;
                    used[x] = true;
                    break;
                }
            }
        }
    }
    fr(i,1,n+1,1){
        if(ans[i]==-1){
            pr(-1); return;
        }
    }
    fr(i,1,n+1,1){
        cout << ans[i] << " ";
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