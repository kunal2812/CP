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

bool isPalindrome(string s){
    string t = s;
    rev(s);
    if(t==s){
        return true;
    }
    return false;
}
void solve(int xx){ 
    int t;
    string s; cin >> s; cin >> t;
    set<string> vis;
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,2));
    int hh = t/60;
    int mm = t%60; int ans = 0;
    while(1){
        string curr = to_string(h);
        if(curr.size()==1){
            curr+='0';
            rev(curr);
        }
        string tmp = to_string(m);
        if(tmp.size()==1){
            tmp+='0';
            rev(tmp);
        }
        curr+=tmp;
        if(vis.find(curr)!=vis.end()){
            break;
        }
        else{
            vis.insert(curr);
            if(isPalindrome(curr)){
                ans++;
            }
        }
        h+=hh;
        m+=mm;
        if(m>=60){
            h++;
        }
        m%=60;
        h%=24;
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
