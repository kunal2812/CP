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
000000 2
000011 4
00xx11
0x0x11
x00x11
x0x011
xx0011

000110 2
010001 2
001111 2
001100 2

111010

6 2
000000 2
010100 4

010111
011101
011110
110101
110110
111100

00111100 5
10100111 2
10110101 2

00001000
00011010
01001100
01011110
01101000
01111010
*/
int ans = 0;

bool check(string a, string b, int m){
    int cnt = 0;
    fr(i,0,sz(a),1){
        if(a[i]==b[i]){
            cnt++;
        }
    }
    return cnt==m;
}

void backtrack(vector<pair<string,int>> &inp, string curr){
    int n = inp[0].ff.size();
    if(curr.size()==n){
        bool f = true;
        fr(i,0,sz(inp),1){
            if(!check(curr,inp[i].ff, inp[i].sc)){
                f = false;
            }
        }
        if(f){
            // cout << curr << endl;
            ans++;
        }
        return;
    }
    fr(i,0,sz(inp),1){
        int pp = 0;
        fr(j,0,sz(curr),1){
            if(curr[j]==inp[i].ff[j]){
                pp++;
            }
        }
        if(pp>inp[i].sc){
            return;
        }
    }
    backtrack(inp, curr+'0');
    backtrack(inp, curr+'1');
}
bool cmp(pair<string,int> x, pair<string,int> y){
    return x.sc<y.sc;
}
void solve(int xx){ 
    int n,m; cin >> n >> m;
    vector<pair<string,int>> inp(m);
    fr(i,0,m,1){
        cin >> inp[i].ff >> inp[i].sc;
    }
    sort(all(inp),cmp);
    backtrack(inp, "");
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
