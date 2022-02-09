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

ll power(ll x, ll y, ll m){
    ll ans = 1;
    while(y){
        if(y&1){
            ans = ((ll)(ans%m)*(x%m))%m;
        }
        x=((ll)(x%m)*(x%m))%m;
        y/=2;
    }
    return ans;
}

ll inv(ll p, ll q, ll m){
    ll expo = m-2;
    while(expo){
        if(expo&1){
            p = ((ll)(p%m)*(q%m))%m;
        }
        q = ((ll)(q%m)*(q%m))%m;
        expo/=2;
    }
    return (p+m)%m;
}

string midstr(string &k){
    int cnt = 0;
    int n = sz(k);
    vll pref(n,0), suff(n,0);
    ll p = 1, m = 1e9 + 7;
    fr(i,0,n,1){
        if(i==0){
            pref[i] = (k[i]-'a'+1)*p; p*=111; p%=m; pref[i]%=m;
        }
        else{
            pref[i] = pref[i-1] + (k[i]-'a'+1)*p; p*=111; p%=m; pref[i]%=m;
        }
    }
    p = 1;
    rfr(i,n-1,0,1){
        if(i==(n-1)){
            suff[i] = (k[i]-'a'+1)*p; p*=111; p%=m; suff[i]%=m;
        }
        else{
            suff[i] = suff[i+1] + (k[i]-'a'+1)*p; p*=111; p%=m; suff[i]%=m;
        }
    }
    int ind = 0; ll h1, h2, h3;
    string ans = "";
    bool f = false;
    fr(i,0,n,1){
        ll h1 = pref[i];
        if(((2*i)+1)<n){
            h2 = inv(suff[i]-suff[(2*i)+1], power(111,n-(2*i)-1,m),m);
            if(h1==h2){
                ind = i;
                f = false;
            }
        }
        if(((2*i)+2)<n){
            h3 = inv(suff[i+1]-suff[(2*i)+2], power(111, n-(2*i)-2, m), m);
            if(h1==h3){
                ind = i;
                f = true;
            }
        }
    }
    if(f){
        fr(i,0,ind+1,1){
            ans+=k[i];
        }
        rfr(i,ind,0,1){
            ans+=k[i];
        }
    }
    else{
        fr(i,0,ind+1,1){
            ans+=k[i];
        }
        rfr(i,ind-1,0,1){
            ans+=k[i];
        }
    }
    // pr(ans);
    return ans;
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