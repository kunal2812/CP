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
void solve(int xx){ 
    int n,k; cin >> n >> k;
    string s; cin >> s;
    bool flag = false; int lose = 0;
    vi segs;
    fr(i,0,n,1){
        if(s[i]=='W'){
            if(!flag){
                segs.pb(i);
            }
            flag = true;
        }
        else{
            lose++;
            if(flag){
                segs.pb(i-1);
            }
            flag = false;
        }
    }
    if(s[n-1]=='W'){
        segs.pb(n-1);
    }
    // for(auto x:segs){
    //     cout << x << " ";
    // }nl;
    vi gap; ll ans = 0;
    fr(i,1,sz(segs),2){
        int len = segs[i]-segs[i-1]+1;
        ans+=(2*(len)-1);
        if((i+1)<sz(segs)){
            gap.pb(segs[i+1]-segs[i]-1);
        }
    }
    sorta(gap);
    // cout << ans << endl;
    // for(auto x:gap){
    //     cout << x<< " ";
    // }nl;
    k = min(k,lose);
    if(segs.empty()){
        ans = max(0,2*k-1);
        pr(ans); return;
    }
    for(auto x:gap){
        if(k>=x){
            k-=x;
            ans+=((x*2)+1);
        }
        else{
            ans+=(2*k);
            k = 0;
            break;
        }
    }
    ans+=(2*k);
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
