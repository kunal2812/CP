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

ll mod = 1000000007;
struct item{
    string s;
    int a,b,c;
};
void Solution(int xx){ 
    int n; cin >> n;
    vector<item> v(n);
    for(int i=0;i<n;i++){
        int k; cin >> k; cin >> v[i].s;
        for(int j=0;j<k;j++){
            string num; cin >> num;
            int t = num.find("-");
            string a = num.substr(0, 2);
            num[t] = '#';
            int tt = num.find("-");
            string b = num.substr(t+1, 2);
            num[tt] = '#';
            int ttt = num.find("-");
            string c = num.substr(tt+1, 2);
            if(a==b && b==c && b[0]==b[1]){
                v[i].a++;
            }
            else if(a[0]>a[1] && a[1]>b[0] && b[0]>b[1] && b[1]>c[0] && c[0]>c[1]){
                v[i].b++;
            }
            else{
                v[i].c++;
            }
        }
    }
    int maxm = INT_MIN;
    for(auto x:v){
        maxm = max(maxm, x.a);
    }
    cout << "If you want to call a taxi, you should call: ";
    bool flag = false;
    for(int j=0;j<n; j++){
        if(v[j].a==maxm){
            if(flag){
                cout << ", "; 
            }
            cout << v[j].s;
            flag = true;
        }
    }
    cout << ".\n";
    maxm = INT_MIN;
    for(auto x:v){
        maxm = max(maxm, x.b);
    }
    cout << "If you want to order a pizza, you should call: ";
    flag = false;
    for(int j=0;j<n; j++){
        if(v[j].b==maxm){
            if(flag){
                cout << ", "; 
            }
            cout << v[j].s;
            flag = true;
        }
    }
    cout << ".\n";
    maxm = INT_MIN;
    for(auto x:v){
        maxm = max(maxm, x.c);
    }
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    flag = false;
    for(int j=0;j<n; j++){
        if(v[j].c==maxm){
            if(flag){
                cout << ", "; 
            }
            cout << v[j].s;
            flag = true;
        }
    }
    cout << ".\n";
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    int i=0;
    Solution(++i);
    return 0;
}
