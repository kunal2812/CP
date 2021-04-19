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

bool Solution1(string s){
    int n = s.length();
    if(s.length()%2==1){
        return false;
    }
    if(s[0]==')' || s[n-1]=='('){
        return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while(T!=0){\
        string s;
        cin >> s;
        if(Solution1(s)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        T--;
    }
    return 0;
}

