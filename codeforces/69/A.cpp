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


int main() {
    int T;
    int i,j,k;
    int N;
    long long A[100000];
    cin >> T;
    ll sum1=0, sum2=0, sum3=0;
    for(int i=0;i<T;i++){
        int x,y,z;
        cin >> x >> y >> z;
        sum1+=x;
        sum2+=y;
        sum3+=z;
    }
    if(sum1==0 && sum2==0 && sum3==0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

