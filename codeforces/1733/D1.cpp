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
    int n; ll x,y; cin >> n >> x >> y;
    string s1,s2; cin >> s1 >> s2;
    ll ans = 0;
    ll pp = 0;
    int cnt = 0;
    vi chunks;
    fr(i,0,n,1){
        if(s1[i]!=s2[i]){
            cnt++;
            pp++;
        }
        else{  
            if(cnt!=0){
                chunks.pb(cnt);
            }
            cnt = 0;
        }
    }
    if(pp%2){
        pr(-1); return;
    }
    if(cnt!=0){
        chunks.pb(cnt);
    }
    bool yep = false;
    fr(i,0,sz(chunks),1){
        // cout << chunks[i] << " ";
        if(chunks[i]>2){
            yep = true;
            ans+=((chunks[i]/2)*y);
            chunks[i]%=2;
        }
    }
    // nl;
    int cnt1 = 0, cnt2 = 0;
    for(auto x:chunks){
        if(x==1){
            cnt1++;
        }
        else if(x==2){
            cnt2++;
        }
    }
    if(cnt2>1){
        ans+=cnt2*y;
        ans+=(cnt1/2)*y;
        cnt2 = 0;
    }
    else if(cnt2==0){
        ans+=(cnt1/2)*y;
    }
    else if(cnt2==1){
        if(cnt1>=2){
            ans+=(2*y);
            cnt1-=2;
            ans+=(cnt1/2)*y;
        }
        else{
            if(yep){
                ans+=y;
            }
            else{
                ans+=min(x,2*y);
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
