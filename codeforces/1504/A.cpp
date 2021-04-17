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
 
 
// for(int i=0;i<n;i++){
//     cin >> a[i];
// }
bool checkpalindrome(string s)
{
    int i,c=0,n;
    n=s.length();
	for(i=0;i<n/2;i++)  
    {
    	if(s[i]==s[n-i-1])
    	c++;
 
 	}
 	if(c==i){
        return true;
 	}
    else{
        return false;}
 }
void Solution(){
    string s;
    cin >> s;
    int n = s.length();
    string x = s;
    string y = s;
    x.insert(0,"a");
    y.insert(n-1,"a");
    if(checkpalindrome(x)==false){
        cout << "YES" << endl << x << endl;
        return;
    }
    if(checkpalindrome(y)==false){
        cout << "YES" << endl << y << endl;
        return;
    }
    cout <<"NO" <<  endl;
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
 