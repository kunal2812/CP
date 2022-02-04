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

ll mod1 = 1000000007;
ll mod2 = 3984992297;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

/*

*/
void solve(int xx){ 
    string s,t; cin >> s >> t;
    int k; cin >> k;
    set<char> good;
    char c = 'a';
    for(auto x:t){
        if(x=='1'){
            good.insert(c);
        }
        c++;
    }
    int cnt=0; int n = sz(s);
    set<pair<ll, ll>> st;
    fr(i,0,n,1){
        int bad = 0;
        ll temp1 = 0, temp2 = 0;
        ll p1 = 31, p2 = 111;
        fr(j,i,n,1){
            temp1+=(((ll)(s[j]-'a'+1)*p1)%mod1); p1 = ((ll)p1*p1)%mod1; temp1%=mod1;
            temp2+=(((ll)(s[j]-'a'+1)*p2)%mod2); p2 = ((ll)p2*p2)%mod2; temp2%=mod2;
            // cout << i << " " << j << " " << temp << endl;
            if(good.find(s[j])==good.end()){
                bad++;
            }
            if(bad>k){
                break;
            }
            else{
                if(st.find({temp1, temp2})!=st.end()){
                    continue;
                }
                // cout << i << " " << j << endl;
                cnt++;
            }
            st.insert({temp1, temp2});
        }
    }
    pr(cnt);
}

int main() {
    fast;
    int t, i=0; 
    // cin >> t;
    // while(t--)  
        solve(++i);
    return 0;
}
