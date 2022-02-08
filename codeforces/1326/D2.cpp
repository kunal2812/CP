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
    string t = "";
    for(char c:k){
        t+='#'; t+=c;
    } t+='#';
    int l = 0, r = -1, n = t.size();
    t = '$'+t+'@';
    vi p(n+2);
    for(int i=1; i<=n; i++){
        p[i] = max(0, min(r-i, p[r+l-i]));
        while(t[i+p[i]]==t[i-p[i]]){
            p[i]++;
        }
        if((i+p[i])>r){
            l = i-p[i]; r = i+p[i];
        }
    }
    l = 1; int ind1 = -1;
    for(int i=1; i<=n; i++){
        if(p[i]==l){
            ind1 = i;
        }
        l++;
    }
    l = 1; int ind2 = -1;
    for(int i=n; i>=1; i--){
        if(p[i]==l){
            ind2 = i;
        }
        l++;
    }
    // cout << t << endl;
    // for(int i=1; i<=n; i++){
    //     cout << p[i] << " ";
    // }nl;
    string m1 = "", ans = "";
    int j;
    if(p[ind1]>p[ind2]){
        j = ind1;
    }
    else{
        j = ind2;
    }
    int tc = p[j];
    bool even = false;
    if(t[j]=='#'){
        even = true;
    }
    while(tc--){
        if(t[j]!='#'){
            ans+=t[j];
        }
        j++;
    }
    for(int i=ans.size()-1; i>=0; i--){
        m1+=ans[i];
    }
    int i=0;
    if(!even)i++;
    for(i; i<ans.size(); i++){
        m1+=ans[i];
    }
    return m1;
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
    string mid = midstr(k);
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