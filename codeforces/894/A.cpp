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
    string s;
    cin >> s;
    int n = s.length();
    int ct = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='Q'){
            for(int j = i+1;j<n;j++){
                if(s[j]=='A'){
                    for(int k = j+1;k<n;k++){
                        if(s[k]=='Q'){
                            ct++;
                        }
                    }
                }
            }
        }
    }
    cout << ct <<  endl;
}

int main() {
    int T;
        Solution();
    return 0;
}

