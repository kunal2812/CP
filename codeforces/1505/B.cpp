#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back

#define  IN for(int i=0;i<n;i++){cin >> a[i];}
#define  OUT for(int i=0;i<n;i++){cout << a[i] << " ";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

int d(long long n) {
  return floor(log10(n) + 1);
}

void Solution(){
    int n;
    cin >> n;
    int ans;
    while(n>9){
        ans=0;
        while(n!=0){
            ans += (n%10);
            n=n/10;
        }
        n = ans;
    }
    cout << n << endl;
}

int main() {
    int T;
        Solution();
    return 0;
}

