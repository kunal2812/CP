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

void solve(int xx){ 
    int n; cin >> n;
    vector<string> all;
    fr(i,0,10,1){
        fr(j,0,10,1){
            if(i==j){
                continue;
            }
            fr(k,0,10,1){
                if(i==k || k==j){
                    continue;
                }
                fr(l,0,10,1){
                    if(i==l || j==l || k==l){
                        continue;
                    }
                    string p = "";
                    p+=(i+'0');
                    p+=(j+'0');
                    p+=(k+'0');
                    p+=(l+'0');
                    all.pb(p);
                }
            }
        }
    }
    vector<bool> flag(sz(all),true);
    fr(i,0,n,1){
        string t; cin >> t;
        int a,b; cin >> a >> b;
        fr(j,0,sz(all),1){
            int cnt1 = 0;
            int cnt2 = 0;
            if(flag[j]){
                set<char> st;
                for(auto x:all[j]){
                    st.insert(x);
                }
                for(auto x:t){
                    if(st.find(x)!=st.end()){
                        cnt2++;
                    }
                }
                cnt1 = (all[j][0]==t[0])+(all[j][1]==t[1])+(all[j][2]==t[2])+(all[j][3]==t[3]);
                cnt2 = cnt2-cnt1;
                // cout << all[j] << " " << cnt1 << " " << cnt2 << endl;
                if(cnt1!=a || cnt2!=b){
                    flag[j] = false;
                }
            }
        }
    }
    int c = count(all(flag),true);
    if(c>1){
        pr("Need more data");
    }
    else if(c==1){
        fr(i,0,sz(all),1){
            if(flag[i]){
                cout << all[i] << endl; return;
            }
        }
    }
    else{
        pr("Incorrect data");
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
// kunal0403