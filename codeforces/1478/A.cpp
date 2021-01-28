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
    int count=0;
    unordered_map<int,int> m;
    for(int i=0;i<N;i++){
        m[A[i]]++;
    }
    
    unordered_map<int,int>::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++){
            count = max(count,itr->second);
    }
    cout << count << endl;
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

