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
    int n,m; cin >> n >> m;
    vector<string > g(n);
    fr(i,0,n,1){
        cin >> g[i];
    }
    fr(j,0,m,1){
        int cnt = 0, prev = 0;
        fr(i,0,n,1){
            if(g[i][j]=='*' && i!=(n-1)){
                cnt++;
            }
            else if(g[i][j]=='o' || (i==(n-1) && g[i][j]=='*')){
                // cout << cnt << " " << i << " " << j << endl;
                int tt = i-1;
                while(tt>=prev){
                    if(cnt>0){
                        g[tt][j] = '*';
                        cnt--;
                    }
                    else{
                        g[tt][j] = '.';
                    }
                    tt--;
                }
                cnt = 0; prev = i+1;
            }
            else if(i==(n-1)){
                // cout << cnt << " " << i << " " << j << endl;
                int tt = i;
                while(tt>=prev){
                    if(cnt>0){
                        g[tt][j] = '*';
                        cnt--;
                    }
                    else{
                        g[tt][j] = '.';
                    }
                    tt--;
                }
                cnt = 0;
            }
        }
    }
    for(auto x:g){
        pr(x);
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
