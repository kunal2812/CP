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

void Solution(string s){
    int n = s.length();
    for(int i=0;i<n;i+=2){
        
        if(s[i]=='a')
            s[i] = 'b';
        else{
            s[i] = 'a';
        }
    }
    for(int j=1;j<n;j+=2){
        
        if(s[j]=='z')
            s[j] = 'y';
        else{
            s[j] = 'z';
        }
    }
    cout << s << endl;
}

int main() {
    int T;
    int i,j,k;
    ll N, K;
    cin >> T;
    while(T!=0){
        string s;
        std::cin >> s;
        Solution(s);
        T--;
    }
    return 0;
}

