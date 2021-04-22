#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define  IN for(int i=1;i<=n;i++){cin >> a[i];}
#define  OUT for(int i=0;i<n;i++){cout << a[i] << " ";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vi> umiv;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    int a[5005];
    int n;
    cin >> n;
    IN;
    sort(a+1, a+n+1);
    int h = a[n];
    int w = n;
    int i = 1;
    int j = n;
    while(a[i]<w){
        i++;
        w--;
    }
    cout << w << endl;
}

int main() {
    fast;
    int T;
    cin >> T;
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

