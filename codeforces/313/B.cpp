#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define  IN for(int i=1;i<=n;i++){cin >> a[i];}
#define  OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    string s;
    cin >> s;
    int m;
    cin >> m;
    int dp[200005];
    int n = s.length();
    dp[0] = 0;
    for(int i=0;i<n;i++){
        dp[i+1] = (s[i]==s[i+1]) + dp[i];
    }
    dp[n]++;
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        cout << dp[r-1] - dp[l-1] << endl;
    }
}

int main() {
    int T;
        Solution();
    return 0;
}

