#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
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
    int n,k;
    cin >> n >> k;
    int a[600];
    IN;
    vector<int> v;
    v.pb(0);
    v.pb(a[1]);
    int c=0;
    for(int i=2;i<=n;i++){
        if((v[i-1]+a[i])>=k){
            v.pb(a[i]);
        }
        else{
            c+=(k-a[i]-v[i-1]);
            v.pb(k-v[i-1]);
        }
    }
    cout << c << endl;
    for(int i=1;i<=n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    fast;
    Solution();
    return 0;
}

