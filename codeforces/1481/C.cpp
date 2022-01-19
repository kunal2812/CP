#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
typedef map<int,int> mii;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umii;

typedef unordered_set<int> usi;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())
#define gtmin(a) *min_element(a.begin(), a.end())

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
/*
7 3 2 1 7 9 4 2 7 9
9 9 2 1 4 9 4 2 3 9
. . x x . x x x . x
9 9 7 4 3
1 2 5 5 9


*/
void solve(int xx){ 
    int n,m; cin >> n >> m;
    vi a(n), b(n), c(m); map<int, vi> mp, pr; vi ans(m,-1);
    fr(i,0,n,1)        cin >> a[i];
    fr(i,0,n,1){
         cin >> b[i];
         pr[b[i]].pb(i);
    }       
    fr(i,0,m,1){
        cin >> c[i]; mp[c[i]].pb(i);
    }
    fr(i,0,n,1){
        if(a[i]!=b[i]){
            if(mp.find(b[i])==mp.end()){
                no;
            }
            else{
                int ind = mp[b[i]].back();
                ans[ind] = i+1;
                mp[b[i]].pop_back();
                if(mp[b[i]].size()==0){
                    mp.erase(b[i]);
                }
            }
        }
    }
    vi p;
    fr(i,0,m,1){
        if(ans[i]==-1){
            // c[i] color he is providing
            if(pr.find(c[i])!=pr.end()){
                ans[i] = pr[c[i]].back()+1;
            }
        }
    }
    int prev = -1;
    rfr(i,m-1,0,1){
        if(ans[i]==-1){
            if(prev==-1){
                no;
            }
            ans[i] = prev;
        }
        prev = ans[i];
    }
    pr("YES");
    for(auto t:ans){
        cout << t << " ";
    }nl;
}

int main() {
    fast;
    int t, i=0; cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
