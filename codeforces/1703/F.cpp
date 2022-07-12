/*
Source for BIT: https://www.codechef.com/viewsolution/68286774
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

int sz;
vector<oms> bit;

int lowbit(int x){
    return x&-x;
}

void add(int i,int x){
    for(;i<=sz;i+=lowbit(i))
        bit[i].insert(x);
}

int query(int i,int x){
// count number strictly smaller than x till ith
    int count = 0;
    for( ; i > 0; i-=lowbit(i)){
        count += bit[i].order_of_key(x);
    }
    return count;
}

int query(int l,int r,int kth,bool cntsmall=false){

    if(cntsmall){
        return query(r,kth) - query(l-1,kth);
    }

    int low = 0, high = 10, ans = 0;
    while(low <= high){
        int mid = (low+high)/2;
        int cnt = query(r,mid) - query(l-1,mid);

        if(cnt < kth){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

void build(vector<int> &v){
    sz = v.size();
    bit.resize(sz+1);
    for(int i=1;i<sz;i++){
        add(i,v[i]);
    }
}

void solve(int xx){ 
    bit.clear();
    int n; cin >> n;
    int x;
    vi a(n+1);
    fr(i,1,n+1,1){
        cin >> x;
        if(x<i){
            a[i] = x;
        }
        else{
            a[i] = INT_MAX;
        }
    }
    build(a);
    ll cnt = 0; ll t;
    fr(i,1,n+1,1){
        if(a[i]<i && a[i]>0){
            t = query(1,a[i]-1,a[i]-1,true);
            // cout << a[i] << " " << i << " "<< t << endl;
            cnt+=t;
        }
    }
    pr(cnt);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
