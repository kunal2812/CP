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
    for(int j=1;j<8;j++){
        umci m;
        int i = j;
        m['A']=i%2;
        i/=2;
        m['B']=i%2;
        i/=2;
        m['C']=i%2;
        int count=0;
        for(int t=0;t<n;t++){
            if(m[s[t]]==0){
                count++;
            }
            else{
                count--;
            }
            if(count<0){
                break;
            }
        }
        if(count==0){
            //cout << j << " ";
            cout<< "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    int i,j,k;
    cin >> T;
    while(T!=0){
        string s;
        std::cin >> s;
        Solution(s);
        T--;
    }
    return 0;
}

