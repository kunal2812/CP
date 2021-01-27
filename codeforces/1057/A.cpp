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

void Solution(int N, int* A){
    unordered_map<int, int> m;
    for(int i=0;i<N-1;i++){
        m[i+2] = A[i];
    }
    vector<int> ans;
    ans.pb(N);
    int z = N;
    while(z!=1){
        z = m[z];
        ans.pb(z);
    }
    int n = ans.size();
    for(int i=0;i<n;i++){
        cout << ans[n-i-1] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    int i,j;
    int N;
    int A[300000];
        std::cin >> N;
        for(i=0;i<N-1;i++){
            cin >> A[i];
        }
        Solution(N,A);
    return 0;
}

