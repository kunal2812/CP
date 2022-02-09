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

ll mod = 1000000009;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

/*

abc dfdce cba

*/

string midstr(string &k){
    string t = k;
    rev(t);
    string p = k+'$'+t;
    int n = sz(p);
    vi pi(n,0);
    int j = 0;
    fr(i,1,n,1){
        j = pi[i-1];
        while(j>0 && p[i]!=p[j]){
            j = pi[j-1];
        }
        if(p[i]==p[j]){
            j++;
        }
        pi[i] = j;
    }
    return p.substr(0,j);
}

void solve(int xx){ 
    string s; cin >> s;
    int n = sz(s), i = 0, j = n-1;
    if(n==1){
        pr(s); return;
    }
    string t = "";
    while(i<j && s[i]==s[j]){
         t+=s[i];
         i++; j--;
    }
    string ans = t;
    rev(t); 
    string k = s.substr(i,j-i+1);
    string mid = "";
    if(k!=""){
        string mid1 = midstr(k);
        rev(k);
        string mid2 = midstr(k);
        if(sz(mid1)>sz(mid2)){
            mid = mid1;
        }
        else{
            mid = mid2;
        }
    }
    ans+=mid; ans+=t;
    pr(ans);
}

int main() {
    fast;
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}