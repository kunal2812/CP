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
    int n;
    ll l;
    ll A[2000];
    cin >> n >> l;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    sort(A, A+n);
    ll maxdiff = 0;
    int d;
    for(int i=0;i<n-1;i++){
        d = A[i+1] - A[i];
        // cout << d << endl;
        if(d>maxdiff){
            maxdiff = d;
        }
    }
    long double t1 = (double)maxdiff/2;
    long double t2 = A[0]-0;
    long double t3 = l - A[n-1];
    cout  << std::setprecision(9) << max(t1, max(t2,t3)) << endl;
}

