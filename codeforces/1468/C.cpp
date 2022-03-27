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

class cmp{
public:
    bool operator() (pii x, pii y) {
        if(x.ff==y.ff){
            return x.sc>y.sc;
        }
        return x.ff<y.ff;
    }
};

void solve(int xx){ 
    int q; cin >> q;
    priority_queue<pii,vector<pii>,cmp> pq;
    set<int> s;
    int id = 0,x,m;
    while(q--){
        cin >> x;
        if(x==1){
            cin >> m;
            pq.push({m,++id});
            s.insert(id);
        }
        else if(x==2){
            cout << *s.begin() << " ";
            s.erase(s.begin());
        }
        else{
            pii t = pq.top(); pq.pop();
            while(!pq.empty() && s.find(t.sc)==s.end()){
                t = pq.top(); pq.pop();
            }
            s.erase(t.sc);
            cout << t.sc << " ";
        }
    }nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
