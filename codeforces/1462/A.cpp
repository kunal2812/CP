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

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    int n;
    ll a[303];
    cin >> n;
    IN;
    vector<ll> ans;
    int i=1,j=n;
    while(i<j){
        ans.pb(a[i]);
        ans.pb(a[j]);
        i++;
        j--;
    }
    if(n%2==1){
        ans.pb(a[i]);
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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

