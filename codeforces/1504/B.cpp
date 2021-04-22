#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
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
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vi> umiv;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1;
    cin >> s2;
    if(s1==s2){
        cout << "YES" << endl;
        return;
    }
    int c0=0;
    int c1=0;
    for(int i=0;i<n;i++){
        if(s1[i]=='0'){
            c0++;
        }
        else{
            c1++;
        }
    }
    bool flag = false;
    int i =n-1;
    while(i>=0){
        // cout << i << " " << c0 << " " << c1 << endl;
        if(s1[i]==s2[i] && flag==true){
            flag=false;
            if(c0!=c1){
                cout << "NO" << endl;
                return;
            }
        }
        if(s1[i]!=s2[i] && flag==false){
            flag=true;
            if(c0!=c1){
                cout << "NO" << endl;
                return;
            }
        }
        if(s1[i]=='0'){
            c0--;
        }
        if(s1[i]=='1'){
            c1--;
        }
        i--;
    }
    cout << "YES" << endl;
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

