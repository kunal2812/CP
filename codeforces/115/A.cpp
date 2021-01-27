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
    m[-1] = 0;
    int y=1;
    int z=1;
    int count=2000;
    while(count){
        for(int i=0;i<N;i++){
            if(m.find(A[i])!=m.end()){
                m[i+1] = m[A[i]]+1;
                z=1;
            }
        }
        count--;
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        //cout << i << " " << m[A[i]] << endl;
        if(ans<m[A[i]]){
            ans=m[A[i]];
        }
    }
    cout << ans+1 << endl;
}

int main() {
    int T;
    int i,j;
    int N;
    int A[300000];
        std::cin >> N;
        for(i=0;i<N;i++){
            cin >> A[i];
        }
        Solution(N,A);
    return 0;
}

