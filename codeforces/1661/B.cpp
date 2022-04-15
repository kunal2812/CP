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

*/

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi ans(32768,-1);
    queue<int> q; q.push(0); ans[0] = 0;
    while(!q.empty()){
        int pp = q.front(); q.pop();
        if((pp&1)==0){
            if(ans[((pp+32768)/2)%32768]==-1){
                q.push(((pp+32768)/2)%32768);
                ans[((pp+32768)/2)%32768] = ans[pp]+1;
            }
            if(ans[pp/2]==-1){
                q.push(pp/2);
                ans[pp/2] = ans[pp]+1;
            }
        }
        if(ans[(pp+32768-1)%32768]==-1){
            q.push((pp+32768-1)%32768);
            ans[(pp+32768-1)%32768] = ans[pp]+1;
        }
    }
    int t, i=0; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << ans[n] << " ";
    }
    nl;
    return 0;
}
