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
    multiset<string> s1,s2,s3;
    string s;
    fr(i,0,n,1){
        cin >> s; s1.insert(s);
    }
    fr(i,0,n,1){
        cin >> s; s2.insert(s);
    }
    fr(i,0,n,1){
        cin >> s; s3.insert(s);
    }
    ll a = 0, b = 0 , c = 0;
    for(auto x:s1){
        if(s2.find(x)==s2.end() && s3.find(x)==s3.end()){
            a+=3;
        }
        else if(s2.find(x)==s2.end()){
            a+=1;
        }
        else if(s3.find(x)==s3.end()){
            a+=1;
        }
    }
    for(auto x:s2){
        if(s1.find(x)==s1.end() && s3.find(x)==s3.end()){
            b+=3;
        }
        else if(s1.find(x)==s1.end()){
            b+=1;
        }
        else if(s3.find(x)==s3.end()){
            b+=1;
        }
    }
    for(auto x:s3){
        if(s2.find(x)==s2.end() && s1.find(x)==s1.end()){
            c+=3;
        }
        else if(s2.find(x)==s2.end() ){
            c+=1;
        }
        else if(s1.find(x)==s1.end()){
            c+=1;
        }
    }
    cout << a  << " " << b << " " << c << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
