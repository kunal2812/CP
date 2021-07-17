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

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())

ll mod = 1000000007;

void Solution(){ 
    int n; cin >> n;
    vi a(n);
    vi b(n);
    usi s;
    umiv m;
    s.reserve(1024);
    s.max_load_factor(0.25);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
        s.insert(a[i]);
        m[a[i]].pb(i);
    }
    stack<int> st;
    for(int i=n;i>=1;i--){
        if(s.find(i)==s.end()){
            st.push(i);
        }
    }
    cout << s.size() << endl;
    for(int i=0;i<n;i++){
        if(s.find(a[i])==s.end()){
            b[i] = st.top();
            st.pop();
        }
        else{
            s.erase(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        if((i+1)==b[i]){
            int j;
            for(auto y:m[a[i]]){
                if(y!=i){
                    j = y;
                    break;
                }
            }
            swap(b[i], b[j]);
        }
    }
    for(auto x:b){
        cout << x << " " ;
    }nl;
}

int main() {
    fast;
    int T;
    cin >> T;
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

