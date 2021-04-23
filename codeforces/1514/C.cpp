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
    int n;
    cin >> n;
    vector<int> v;
    ll pp = 1;
    for(int i=1;i<n;i++){
        if(__gcd(i,n)==1){
            v.pb(i);
            pp = (pp*i)%n;
        }
    }
    cout << v.size() - (pp!=1) << endl;
    for(int i=0;i<(v.size()-(pp!=1));i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    fast;
    Solution();
    return 0;
}

