#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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

*/

string op1(int x){
    return "insert " + to_string(x);
}

string op2(int x){
     return "getMin " + to_string(x);
}

string op3(){
    return "removeMin";
}

void solve(int xx){ 
    int n; cin >> n;
    multiset<int> m;
    string op; int x; vector<string> ans;
    for(int i=0; i<n; i++){
        cin >> op;
        if(op=="insert"){
            cin >> x;
            m.insert(x);
            ans.pb(op1(x));
        }
        else if(op=="getMin"){
            cin >> x;
            if(m.find(x)==m.end()){
                ans.pb(op1(x));
                m.insert(x); 
            }
            while(m.size() && *m.begin()<x){
                ans.pb(op3());
                auto del = m.find(*m.begin());
                m.erase(del);
            }
            ans.pb(op2(x));
        }
        else{
            if(m.size()){
                auto del = m.find(*m.begin());
                m.erase(del);
            }
            else{
                ans.pb(op1(0));
            }
            ans.pb(op3());
        }
    }
    cout << ans.size() << endl;
    for(auto x:ans){
        cout << x << endl;
    }
}

int main() {
    fast;
    int t, i=0; 
    // cin >> t;
    // // while(t--)  
        solve(++i);
    return 0;
}
