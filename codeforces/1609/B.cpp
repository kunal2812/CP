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

#define yes cout << "YES" << endl; return
#define no  cout << "NO" << endl; return
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl
#define nf string::npos

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
    int n,q; 
    cin >> n >> q;
    string s;
    cin >> s;
    int curr=0;
    for(int i=0;i<(n-2);i++){
        if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
            curr++;
        }
    }
    int l = n;
        // cout << curr << endl;
    fr(i,0,q,1){
        int kk; char c;
        cin >> kk >> c;
        kk--;
        if(c=='a' && s[kk]=='b'){
            if((kk-1)>=0 && (kk+1)<l && s[kk-1]=='a' && s[kk+1]=='c'){
                curr--;
            }
            if((kk+2)<l && s[kk+1]=='b' && s[kk+2]=='c'){
                curr++;
            }
        }
        else if(c=='a' && s[kk]=='c'){
            if((kk-2)>=0 && s[kk-1]=='b' && s[kk-2]=='a'){
                curr--;
            }
            if((kk+2)<l && s[kk+1]=='b' && s[kk+2]=='c'){
                curr++;
            }
        }
        else if(c=='b' && s[kk]=='a'){
            if((kk+2)<l && s[kk+1]=='b' && s[kk+2]=='c'){
                curr--;
            }
            if((kk-1)>=0 && (kk+1)<l && s[kk-1]=='a' && s[kk+1]=='c'){
                curr++;
            }
        }
        else if(c=='b' && s[kk]=='c'){
            if((kk-2)>=0 && s[kk-1]=='b' && s[kk-2]=='a'){
                curr--;
            }
            if((kk-1)>=0 && (kk+1)<l && s[kk-1]=='a' && s[kk+1]=='c'){
                curr++;
            }
        }
        else if(c=='c' && s[kk]=='a'){
            if((kk+2)<l && s[kk+1]=='b' && s[kk+2]=='c'){
                curr--;
            }
            if((kk-2)>=0 && s[kk-1]=='b' && s[kk-2]=='a'){
                curr++;
            }
        }
        else if(c=='c' && s[kk]=='b'){
            if((kk-1)>=0 && (kk+1)<l && s[kk-1]=='a' && s[kk+1]=='c'){
                curr--;
            }
            if((kk-2)>=0 && s[kk-1]=='b' && s[kk-2]=='a'){
                curr++;
            }
        }
        s[kk] = c;
        cout << curr << endl;
    }
}

int main() {
    fast;
    // int T;
    // cin >> T;
    // int i=0;
    // while(T!=0){
        Solution(0);
    //     T--;
    // }
    return 0;
}
