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
    vector<pii> v;
    int n;
    ll a[100005];
    cin >> n;
    IN;
    ll dp[n+10];
    dp[0]=0;
    int c1=0;
    int c2=0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1]+min(abs(a[i]-1), abs(a[i]+1));
        if(abs(a[i]-1)<abs(a[i]+1)){
            c1++;
        }
        else if(abs(a[i]-1)>abs(a[i]+1)){
            c2++;
        }
    }
    int eq = n-(c1+c2);
    int t=0;
    if(c2%2!=0){
        if(eq!=0){
            t=0;
        }
        else{
            t=2;
        }
    }
    cout << dp[n]+t << endl;
}

int main() {
    fast;
    Solution();
    return 0;
}

