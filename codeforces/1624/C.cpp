#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

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

ll pow2[31];

void init(){
    pow2[0] = 1;
    fr(i,1,32,1){
        pow2[i] = 2*pow2[i-1];
    }
}

void Solution(int xx){ 
    int n; cin >> n;
    vi a(n);
    set<int> s;
    fr(i,0,n,1){
        cin >> a[i];
        if(a[i]<=n && s.find(a[i])==s.end()){
            s.insert(a[i]);
        }
        else{
            fr(j,0,32,1){
                ll t = a[i]/pow2[j];
                if(t<=0){
                    break;
                }
                if(t>0 && t<=n && s.find(t)==s.end()){
                    s.insert(t);
                    break;
                }
            }
        }
    }
    // fr(i,0,n,1){
    //     if(s.find(a[i])==s.end()){
    //         fr(j,0,32,1){
    //             ll t = a[i]/pow2[j];
    //             if(t<=0){
    //                 break;
    //             }
    //             if(t>0 && t<=n && s.find(t)==s.end()){
    //                 s.insert(t);
    //                 break;
    //             }
    //         }
    //     }
    // }
    if(s.size()==n){
        yes;
    }no;
}

int main() {
    fast; init();
    int t, i=0;
    cin >> t;
    while(t--){
        Solution(++i);
    }
    return 0;
}
