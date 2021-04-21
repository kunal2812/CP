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

void Solution(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(s[i]=='*'){
            v.pb(i);
        }
    }
    int i=0;
    int j = v.size()-1;
    s[v[i]] = 'x';
    s[v[j]]='x';
    int prev = v[i];
    i++;
    while(prev+k < v[j]){
        while((v[i] - prev) <= k){
            i++;
        }
        s[v[--i]] = 'x';
        prev = v[i];
    }
    int ct=0;
    for(int i=0;i<n;i++){
        if(s[i]=='x'){
            ct++;
        }
    }
    cout << ct << endl;
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

