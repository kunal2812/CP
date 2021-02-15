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
 
void Solution(ll N){
    N--;
    ll a = sqrt(1+(2*N));
    if(a%2==1){
        cout << a/2 << endl;
    }
    else{
        cout << (a/2) - 1 << endl;
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
        Solution( N);
        T--;
    }
    return 0;
}