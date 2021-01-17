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

void Solution(int w, int h, ll n){
    if(n==1){
        cout << "YES" << endl;
        return;
    }
    int count=1;
    while(w%2==0 || h%2==0){
        if(w%2==0){
            count*=2;
            w=w/2;
        }
        else if(h%2==0){
            count*=2;
            h=h/2;
        }
        if(count>=n){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    int i,j,k;
    int w,h;
    long long n;
    long long A[100000];
    cin >> T;
    while(T!=0){
        std::cin >> w >> h >> n;
        Solution(w,h,n);
        T--;
    }
    return 0;
}

