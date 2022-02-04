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

bool equal(char c, int cnts1, int cnts0){
    if(c=='0' && cnts0>0){
        return true;
    }
    if(c=='1' && cnts1>0){
        return true;
    }
    return false;
}

void solve(int xx){ 
    string s, t; cin >> s >> t;
    int n = sz(s), m = sz(t);
    if(m>n){
        pr(s); return;
    }
    int cnts1 = 0, cntt1 = 0;
    for(auto x:s){
        if(x=='1'){
            cnts1++;
        }
    }
    for(auto x:t){
        if(x=='1'){
            cntt1++;
        }
    }
    int cnts0 = n-cnts1, cntt0 = m-cntt1;
    vi pi(n,0);
    fr(i,1,m,1){
        int j = pi[i-1];
        while(j>0 && t[i]!=t[j]){
            j = pi[j-1];
        }
        if(t[i]==t[j]){
            j++;
        }
        pi[i] = j;
    }
    // fr(i,0,m,1){
    //     cout << pi[i] << " ";
    // }nl;
    string ans = ""; int i=0;
    while(cnts1>0 && cnts0>0){
        if(i<m){
            if(t[i]=='1' && cnts1>0){
                ans+='1';
                cnts1--;
            }
            else if(t[i]=='0' && cnts0>0){
                ans+='0';
                cnts0--;
            }
            else{
                break;
            }
        }
        else{
            int j = pi[i-1];
            while(j>0 && !equal(t[j], cnts1, cnts0)){
                j = pi[j-1];
            }
            if(equal(t[j], cnts1, cnts0)){
                ans+=t[j];
                j++;
            }
            pi[i] = j;
            if(ans[i]=='1'){
                cnts1--;
            }
            else if(ans[i]=='0'){
                cnts0--;
            }
        }
        i++;
    }
    // fr(i,0,n,1){
    //     cout << pi[i] << " ";
    // }nl;
    // pr(ans);
    while(cnts1>0){
        ans+='1';
        cnts1--;
    }
    while(cnts0>0){
        ans+='0';
        cnts0--;
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
