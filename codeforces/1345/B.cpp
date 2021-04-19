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
ll dp[100005];
void initialize(){
    dp[0] = 0;
    for(int i=1;i<100005;i++){
        dp[i] = dp[i-1] + (2*i) + (i-1);
    }
}

int next(int target, int end) 
{ 
    int start = 0; 
    int ans = -1; 
    while (start <= end) 
    { 
        int mid = (start + end) / 2; 
  
        // Move to the left side if the target is smaller 
        if (dp[mid] > target) 
        { 
            end = mid - 1; 
        } 
  
        // Move right side 
        else 
        { 
            ans = mid; 
            start = mid + 1; 
        } 
    } 
    return dp[ans]; 
} 

void Solution(){
    int n;
    cin >> n;
    // for(int i=10000; i<350000;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    int ans=0;
    ll t = dp[100000];
    while(n>=0 && t>0){
        t = next(n, 100000);
        n = n-t;
        // cout << t << " " << n << endl;
        ans++;
    }
    --ans;
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    initialize();
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

