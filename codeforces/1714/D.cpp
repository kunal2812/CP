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

ll mod = 1000000007;

/*

*/
void solve(int xx){ 
    string t; cin >> t;
    int n; cin >> n;
    vector<string> s(n);
    fr(i,0,n,1){
        cin >> s[i];
    }
    vector<pii> ans;
    int p = -1;
    while(p!=(int)(t.size()-1)){
        int k = p+1;
        int str = -1, maxm = 0, pp = -1;
        while(k>=0){
            for(int i=0;i<n;i++){
                int q = 0, r = k;
                int c = 0;
                while(q<s[i].size() && r<t.size() && s[i][q]==t[r]){
                    q++, r++, c++;
                }
                // cout << i << " " << k << " " << c << endl;
                if(q==s[i].size() && (c-(p+1-k))>maxm){
                    maxm = max(0,c-(p+1-k));
                    str = i;
                    pp = k;
                }
            }
            k--;
        }
        // cout << str+1 << " " << pp+1 << " ";
        if(maxm==0){
            pr(-1); return;
        }
        else{
            ans.pb({str+1, pp+1});
            p+=maxm;
        }
        // cout << p << endl;
    }
    cout << ans.size() << endl;
    for(auto x:ans){
        cout << x.ff << " " << x.sc << endl;
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
