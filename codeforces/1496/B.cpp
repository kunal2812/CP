#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=0;i<n;i++){cin >> a[i];}
#define OUT for(int i=0;i<n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second

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
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

ll mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    ll n,k;
    cin >> n >> k;
    usi s;
    ll a[100005];
    for(int i=0;i<n;i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(a, a+n);
    ll ma = a[n-1];
    ll mex = 0;
    ll prev_dd = 0;
    while(k!=0){
        while(s.find(mex)!=s.end()){
            mex++;
        }
        ll dd = ceil((dc)(ma+mex)/2);
        if(mex==dd){
            cout << (ll)(s.size()+k) << endl; return;
        }
        // cout << mex << " mex " << dd << " dd" << endl;
        s.insert(dd);
        ma = max(dd,ma);
        k--;
        if(dd!=mex){
            break;
        }
        prev_dd = dd;

    }
    cout << s.size() << endl;
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

