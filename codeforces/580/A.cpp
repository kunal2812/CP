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

void Solution(ll *a, int n){
    int max=1;
    int curr=1;
    for(int i=0;i<n-1;i++){
        if(a[i+1]>=a[i]){
            curr++;
        }
        else{
            if(curr>max){
                max = curr;
            }
            curr = 1;
        }
    }
    if(curr>max){
        max = curr;
    }
    cout << max <<  endl;
}

int main() {
    int T;
    int i,j,k;
    int N;
    long long A[100009];
    std::cin >> N;
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    Solution(A, N);
    return 0;
}

