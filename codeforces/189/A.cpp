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
    
    cout << endl;
}

int main() {
    int T;
    int i,j,k;
    int n,a,b,c;
    std::cin >> n >> a >> b >> c;
    int ans = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int l = n - (i*a) - (j*b);
            if(l%c==0 && l>=0){
                int k = l/c;
                int t = i+j+k;
                if(t>ans){
                    ans = t;
                    //cout << i<<j<< k;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

