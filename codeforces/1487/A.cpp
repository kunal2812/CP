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

void Solution(ll *A, int N){
    sort(A, A+N);
    int count=1;
    for(int i=0;i<N-1;i++){
        if(A[i+1]==A[i]){
            count++;
        }
        else{
            break;
        }
    }
    cout << N-count << endl;
}

int main() {
    int T;
    int i,j,k;
    int N;
    long long A[100000];
    cin >> T;
    while(T!=0){
        std::cin >> N;
        for(i=0;i<N;i++){
            cin >> A[i];
        }
        Solution(A, N);
        T--;
    }
    return 0;
}

