#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

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
n=1 true

*/

map<int,int> m;

bool check(ll sum, map<int, int> &s){
    if(sum==1){
        if(s.find(sum)!=s.end() && s[sum]>m[sum]){
            m[sum]++;
            return true;
        }
        return false;
    }
    if(s.find(sum)!=s.end() && s[sum]>m[sum]){
        m[sum]++;
        return true;
    }
    if(check(sum/2, s) && check(sum-(sum/2),s)){
        return true;
    }
    return false;
}

void solve(int xx){ 
    m.clear();
    int n; cin >> n;
    vi a(n); map<int, int> s;
    ll sum = 0;
    fr(i,0,n,1){
        cin >> a[i]; s[a[i]]++; sum+=a[i];
    }
    bool ok = check(sum,s);
    // for(auto x:m){
    //     cout << x.ff << " " << x.sc << endl;
    // }
    if(ok){
        for(auto x:m){
            if(m[x.ff]!=s[x.ff]){
                no;
            }
        }
        yes;
    }
    else{
        no;
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
