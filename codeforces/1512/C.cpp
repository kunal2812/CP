#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl;


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
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

ll mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.length() - 1;
  
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
}

void Solution(){
    string s;
    int a,b;
    cin >> a>>b;
    cin >> s;
    int i=0;
    int j=s.length()-1;
    for(int i=0;i<=j;i++){
        if(s[i]=='1'){
            b--;
        }
        else if(s[i]=='0'){
            a--;
        }
    }
    if(a<0 || b<0){
        cout << -1 << endl; return;
    }
    // cout << s << " " << a << " " << b << endl;
    while(i<j){
        if(s[i]=='?' && s[j]!='?'){
            s[i] = s[j];
            if(s[i]=='1'){
                b--;
            }
            else{
                a--;
            }
        }
        else if(s[i]!='?' && s[j]=='?'){
            s[j] = s[i];
            if(s[i]=='1'){
                b--;
            }
            else{
                a--;
            }
        }
        if(a<0 || b<0){
            cout << -1 << endl; return;
        }
        i++;
        j--;
    }
    i=0;
    j=s.length()-1;
    while(i<j){
        if(s[i]=='?' && s[j]=='?'){
            if(b>a){
                s[i]='1';
                s[j]='1';
                b-=2;
            }
            else{
                s[i]='0';
                s[j]='0';
                a-=2;
            }
        }
        if(a<0 || b<0){
            cout << -1 << endl; return;
        }
        i++;
        j--;
    }
    if(i==j && s[i]=='?'){
        if(a==1){
            s[i]='0';
        }
        else{
            s[i]='1';
        }
    }
    if(isPalindrome(s)){
        cout << s << endl;
    }
    else{
        cout << -1 << endl;
    }
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

