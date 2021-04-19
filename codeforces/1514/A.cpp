#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define  IN for(int i=1;i<=n;i++){cin >> a[i];}
#define  OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, vi> umiv;
typedef unordered_map<int, int> umii;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }


void Solution(){
    int n;
    cin >> n;
    ll a[100];
    IN;
    for(int i=1;i<=n;i++){
        int t = sqrt(a[i]);
        if((t*t)!=a[i]){
            cout << "YES" << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

