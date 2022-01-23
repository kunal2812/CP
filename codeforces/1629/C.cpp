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
10
0 0 2 1 1 1 0 0 1 1
1 1 1 3 3 3 3 3 3 3
3 3 3 2 2 2 2 2 0 0
*/

int mex(vi a, int l, int r, int n){
    set<int> s;
    fr(i,l,r+1,1){
        s.insert(a[i]);
    }
    fr(i,0,n+1,1){
        if(s.find(i)==s.end()){
            return i;
        }
    }
}
void solve(int xx){ 
    int n; cin >> n;
    vi a(n);
    fr(i,0,n,1){
        cin >> a[i];
    }
    vi premex(n), suffmex(n);
    set<int> s;
    fr(i,0,n+1,1){
        s.insert(i); 
    }
    fr(i,0,n,1){
        s.erase(a[i]);
        premex[i] = *s.begin();
    }
    fr(i,0,n+1,1){
        s.insert(i); 
    }
    rfr(i,n-1,0,1){
        s.erase(a[i]);
        suffmex[i] = *s.begin();
    }
    vi ans;
    int prev = 0;
    int mexlr = premex[n-1];
    s.clear();
    fr(i,0,n,1){
        s.insert(a[i]);
        if(a[i]==prev){
            fr(i,prev,n+1,1){
                if(s.find(i)==s.end()){
                    prev = i;
                    break;
                }
            }
        }
        if(prev==mexlr){
            ans.pb(prev);
            s.clear();
            prev = 0;
            mexlr = suffmex[i+1];
        }
    }
    pr(sz(ans));
    for(auto x:ans){
        cout << x << " ";
    }nl;
}

int main() {
    fast;
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}