/* https://atcoder.jp/contests/dp/tasks/dp_o?lang=en */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
ll m = 1e9 + 7;
ll dp[1<<21];
int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    dp[0] = 1;
    for(int mask=0; mask<(1<<n); mask++){
        int t = __builtin_popcount(mask); 
        // t--;
        for(int j=0; j<n; j++){
            if(mask&(1<<j) && a[t-1][j]){
                dp[mask] += dp[mask^(1<<j)];
                dp[mask]%=m;
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}
