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
    vi a(n);
    vector<mii> mp(n);
    fr(i,0,n,1){
        cin >> a[i];
        if(i){
            fr(j,1,27,1){
                mp[i][j] = mp[i-1][j];
            }
        }
        mp[i][a[i]]++;
    }
    if(n==1){
        pr(1); return;
    }
    int ans = 0; int cntL, cntR, left, right;
    fr(i,1,27,1){
        left = 0;
        right = n-1;
        cntL = 0, cntR = 0;
        while(left<right){
            // cout << i << " "<< left << " " << right << " " << cntL << " " << cntR << endl;
            if(cntL==cntR){
                fr(j,1,27,1){
                    if(j==i){
                        continue;
                    }
                    int mid = 0;
                    if((left-1)>=0){
                        mid = mp[right][j]-mp[left-1][j];
                    }
                    else{
                        mid = mp[right][j];
                    }
                    ans = max(ans,cntL+cntR+mid);
                }
                // cout << ans << " " << cntL << endl;
                if(a[left]==i){
                    cntL++;
                }
                if(left!=right && a[right]==i){
                    cntR++;
                }
                left++; right--;
                
            }
            else{
                if(cntL<cntR){
                    while(left<right && cntL<cntR){
                        if(a[left]==i){
                            cntL++;
                        }
                        left++;
                    }
                }
                else{
                    while(left<right && cntL>cntR){
                        if(a[right]==i){
                            cntR++;
                        }
                        right--;
                    }
                }
            }
        }
        if(cntL==cntR){
            // cout << "End " << ans << " " << cntL << " " << left << " " << right << endl;
            fr(j,1,27,1){
                if(j==i){
                    continue;
                }
                int mid = 0;
                if((left-1)>=0){
                    mid = mp[right][j]-mp[left-1][j];
                }
                else{
                    mid = mp[right][j];
                }
                ans = max(ans,cntL+cntR+mid);
            }
        }
    }
    pr(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
// kunal0403