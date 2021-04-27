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
    ll n;
    cin >> n;
    vector<ll> w;
    vector<ll> h;
    ll sumW = 0;
    w.pb(0);
    h.pb(0);
    ll hMax = 0;
    ll ind = 0;
    for(int i=1;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        w.pb(a);
        h.pb(b);
        sumW+=a;
        // cout << sumW << " ";
        if(b>hMax){
            ind = i;
        }
        hMax = max(hMax, b);
    }
    // cout << endl;
    sort(h.begin(), h.end());
    for(int i=1;i<=n;i++){
        // cout << sumW << " " << w[i] << " " << hMax << endl;
        if(i!=ind){
            cout << (sumW-w[i])*(hMax) << " ";    
        }
        else{
            cout << (sumW-w[i])*(h[n-1]) << " ";
        }
    }
    cout << endl;
}

int main() {
    fast;
        Solution();
    return 0;
}

