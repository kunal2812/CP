#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;

long long mod = 1000000007;

void Solution(int *a, int n, int k){
    ll dp[500009];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1] + a[i];
        if(i>k){
            dp[i]-=a[i-k];
        }
        // cout << dp[i] << " ";
    }
    int ans = INT_MAX   ;
    int index = 0;
    for(int j=k;j<=n;j++){
        if(dp[j]<ans){
            ans = dp[j];
            index = j;
        }
    }
    cout << index-k+1 << endl;
}

int main() {
    int T;
    int i,j,k;
    int N;
    int K;
    int A[500009];
    std::cin >> N >> K;
    for(i=1;i<=N;i++){
        cin >> A[i];
    }
    Solution(A, N, K);
    return 0;
}

