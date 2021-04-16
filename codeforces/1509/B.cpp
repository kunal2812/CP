#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;

long long mod = 1000000007;


bool Solution(string s, int n){

    int t=0;
    int x,y;
    x=0;
    y=0;
    for(int i=0;i<n;i++){
        if(s[i]=='T'){
            t++;
            x++;
        }
        else{
            t--;
            y++;
        }
        if(t<0){
            return false;;
        }
    }
    if(x==(2*y)){
        return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while(T!=0){
        int n;
        string s;
        cin >> n;
        cin >> s;
        string s1;
        s1 = s;
        reverse(s.begin(), s.end());
        if(Solution(s,n) && Solution(s1,n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO"<< endl;
        }
        T--;
    }
    return 0;
}

