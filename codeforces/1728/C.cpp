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
    int n; cin >> n;
    int x; multiset<int> s1,s2;
    fr(i,0,n,1) {
        cin >> x; s1.insert(x);
    }
    fr(i,0,n,1) {
        cin >> x; 
        if(s1.find(x)!=s1.end()){
            s1.erase(s1.find(x));
        }
        else{
            s2.insert(x);
        }
    }
    int ans = 0;
    while(!s1.empty()){
        int t1 = *s1.rbegin();
        int t2 = *s2.rbegin();
        if(t1>t2){
            s1.erase(s1.find(t1));
            int kp = log10(t1)+1;
            if(s2.find(kp)!=s2.end()){
                s2.erase(s2.find(kp));
            }
            else{
                s1.insert(kp);
            }
            ans++;
        }
        else{
            s2.erase(s2.find(t2));
            int kp = log10(t2)+1;
            // cout << t1 << " " << t2 << " " << kp << endl;
            if(s1.find(kp)!=s1.end()){
                s1.erase(s1.find(kp));
            }
            else{
                s2.insert(kp);
            }
            ans++;
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
