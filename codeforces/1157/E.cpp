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
0 1 2 1
1 3 2 1


0 1 1 2
1 1 2 3

1 2 3 1

7
5 3 4 3
4 3 5 1
0 0 0 3

*/
void solve(int xx){ 
    int n; cin >> n; 
    vi a(n), c(n);
    mii m;
    fr(i,0,n,1){
        cin >> a[i];
    }
    int x;
    fr(i,0,n,1){
        cin >> x; 
        m[x]++;
    }
    int t,t1,t2;
    fr(i,0,n,1){
        if(m.find(n-a[i])!=m.end() && m[n-a[i]]>0){
            t = n-a[i];
        }
        else{
            auto p1 = m.begin();
            auto p2 = m.lower_bound(n-a[i]);
            t1 = (*p1).ff;
            if(p2==m.end()){
                t2 = (*m.rbegin()).ff;
            }
            else{
                t2 = (*p2).ff;
            }
            if((t1+a[i])%n<(t2+a[i])%n){
                t = t1;
            }
            else{
                t = t2;
            }
        }
        // cout << a[i] << " " << t << endl;
        cout << (t+a[i])%n << " ";
        m[t]--;
        if(m[t]==0){
            m.erase(t);
        }
    }nl;
}

int main() {
    fast;
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}