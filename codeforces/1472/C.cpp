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

void Solution(ll *arr, int N){
    vll dp(N+1);
    dp[0]=0;
    int j;
    for(int i=N;i>=1;i--){
        dp[i] = arr[i];
        j = i + arr[i];
        if(j<=N){
            dp[i]+=dp[j];
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    int T;
    int i,j,k;
    int N;
    ll A[300000];
    cin >> T;
    while(T!=0){
        std::cin >> N;
        A[0]=0;
        for(i=1;i<=N;i++){
            cin >> A[i];
        }
        Solution(A, N);
        T--;
    }
    return 0;
}

