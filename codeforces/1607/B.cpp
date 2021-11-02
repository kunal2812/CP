#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl;

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vi> umiv;
// m.reserve(1024);
// m.max_load_factor(0.25);
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())

#define printA(a) for(auto x:a){ cout << x << " "; }nl;
// To rotate an array
// rotate(v.begin(), v.end()+k, v.end())

// To fill consecutive values in a vector
// iota(all(v),1);

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void Solution(int xx){ 
    ll x, n; cin >> x >> n;
    ll ans = x;
    if(x>=0){
        if(x%2==1){
            ll t = (n/4)*4;
            t++;
            ll k = n%4;
            if(k>=1){
                x+=t;
                t++;
            }
            if(k>=2){
                x-=t;
                t++;
            }
            if(k>=3){
                x-=t;
                t++;
            }
            if(k>=4){
                x+=t;
                t++;
            }
            pr(x); return;
        }
        else{
            ll t = (n/4)*4;
            t++;
            ll k = n%4;
            if(k>=1){
                x-=t;
                t++;
            }
            if(k>=2){
                x+=t;
                t++;
            }
            if(k>=3){
                x+=t;
                t++;
            }
            if(k>=4){
                x-=t;
                t++;
            }
            pr(x); return;
        }
    }
    else {
        if(abs(x)%2==1){
            ll t = (n/4)*4;
            t++;
            ll k = n%4;
            if(k>=1){
                // cout << x << "  " << t << endl;
                x+=t; 
                t++;
            }
            if(k>=2){
                x-=t;
                t++;
            }
            if(k>=3){
                x-=t;
                t++;
            }
            if(k>=4){
                x+=t;
                t++;
            }
            pr(x); return;
        }
        else{
            ll t = (n/4)*4;
            t++;
            ll k = n%4;
            if(k>=1){
                x-=t;
                t++;
            }
            if(k>=2){
                x+=t;
                t++;
            }
            if(k>=3){
                x+=t;
                t++;
            } 
            if(k>=4){
                x-=t;
                t++;
            }
            pr(x); return;
        }
    }
}

int main() {
    fast;
    int T;
    cin >> T;
    int i=0;
    while(T!=0){
        Solution(++i);
        T--;
    }
    return 0;
}
