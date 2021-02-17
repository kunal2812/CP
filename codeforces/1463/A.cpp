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

void Solution(ll a, ll b, ll c){
    ll mini = min(a, min(b,c));
    ll n = (a+b+c)/9;
    if((a+b+c)%9==0 && mini>=n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    int i,j,k;
    int N;
    long long A[100000];
    cin >> T;
    while(T!=0){
        ll a,b,c;
        cin >> a >> b >> c;
        Solution(a,b,c);
        T--;
    }
    return 0;
}

