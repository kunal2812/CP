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
6 5

2 3
2 1
3 4
6 5
4 5

1 -> 2,3
2 -> 2,1
3 -> 3,4
4 -> 6,5
5 -> 4,5

1 -> 1,2
2 -> 4,3
3 -> 1,4
4 -> 3,4 

*/
int par[100005];
int find(int x){
    if(par[x]==x){
        return x;
    }
    return par[x] = find(par[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y){
        par[x] = y;
    }
}

void solve(int xx){ 
    int n,k; cin >> n >> k;
    fr(i,1,n+1,1){
        par[i] = i;
    }
    int x, y;
    int ans = 0;
    fr(i,0,k,1){
        cin >> x >> y;
        if(find(x)==find(y)){
            ans++;
        }
        else{
            uni(x,y);
        }
    }
    pr(ans);
}

int main() {
    fast;
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
