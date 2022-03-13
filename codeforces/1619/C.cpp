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

bool check(string a, string b, string s){
    string ans = "";
    while(sz(a)!=sz(b)){
        b = "0"+b;
    }    
    while(sz(a)!=sz(b)){
        a = "0"+a;
    }
    // cout << a << " " << b << " " << s << endl;
    rfr(i,sz(a)-1,0,1){
        int aa = a[i]-'0';
        int bb = b[i]-'0';
        string p = to_string(aa+bb); rev(p);
        ans+=p;
    }
    rev(ans);
    // cout << ans << " " << s << endl;
    if(stoll(ans)!=stoll(s)){
        return false;
    }
    return true;
}

void solve(int xx){ 
    string a,s; cin >> a >> s;
    a = "0000000000000000000"+a;
    string b = ""; int j = sz(s)-1;
    rfr(i,sz(a)-1,0,1){
        if(j<0){
            if(i>=0 && a[i]!='0'){
            pr(-1); return;}
            break;
        }
        string t = ""; t+=a[i];
        int aa = stoi(t); t = ""; t+=s[j];
        int ss = stoi(t); j--;
        int bb = ss-aa;
        if(bb<0){
            if(j<0){
                if(i>=0 && a[i]!='0'){
                pr(-1); return;}
                break;
            }
            ss+=(10*(s[j]-'0')); j--;
            bb = ss-aa;
            if(bb<0 || bb>=10){
                pr(-1); return;
            }
        }
        b+=to_string(bb);
    }
    rev(b);
    if(check(a,b,s)){
        pr(stoll(b));
    }
    else{
        pr(-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}