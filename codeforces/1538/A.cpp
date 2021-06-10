#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl;


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
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

ll mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    int n;
    cin >> n;
    int a[105];
    int maxind=-1;
    int minind = -1;
    int maxm = INT_MIN;
    int minm = INT_MAX;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]>maxm){
            maxm = a[i];
            maxind = i;
        }
        if(a[i]<minm){
            minm = a[i];
            minind = i;
        }
    }
    int mlmax = n-maxind;
    int mlmin = n-minind;
    int mrmax = maxind+1;
    int mrmin = minind+1;
    int ans = min(max(mlmax,mlmin), max(mrmax,mrmin));
    int c = min(mlmax+mrmin, mrmax+mlmin);
    ans = min(ans,c);
    cout <<  ans << endl;
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
 