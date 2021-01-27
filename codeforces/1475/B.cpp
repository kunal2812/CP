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
/*
for(int i=0;i<N;i++){
    cout << arr[i] << endl;
}
*/
void Solution(ll N){
    int y = (ll)N%2020;
    int z = (N-y)/2020;
    if((z-y)>=0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl; 
    }
}

int main() {
    int T;
    int i,j,k;
    ll N;
    long long A[100000];
    cin >> T;
    while(T!=0){
        std::cin >> N;
        Solution(N);
        T--;
    }
    return 0;
}

