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
void Solution(int *a, int *c ,int N){
    int count=0;
    for(int i=1;i<=N;i++){
        if(c[i]!=c[a[i]]){
             count++;
        }
    }
    cout << count << endl;
}

int main() {
    int T;
    int i,j,k;
    int N;
    int A[11000];
    int C[11000];
    std::cin >> N;
    A[0]=0;
    A[1]=0;
    for(i=2;i<=N;i++){
        cin >> A[i];
    }
    C[0]=0;
    for(i=1;i<=N;i++){
        cin >> C[i];
    }
    Solution(A, C, N);
    return 0;
}

