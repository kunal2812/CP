#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=0;i<n;i++){cin >> a[i];}
#define OUT for(int i=0;i<n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;


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
    string s,t;
    cin >> s >> t;
    if(s==t){
        yes;
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            v.pb(i);
        }
    }
    if(v.size()>2){
        no;
    }
    if(v.size()==1){
        char temp = s[v[0]];
        s[v[0]] = t[v[0]];
        t[v[0]] = temp;
        if(s==t){
            yes;
        }
        else{
            no;
        }
    }
    if(v.size()==2){
        char temp = s[v[0]];
        s[v[0]] = t[v[1]];
        t[v[1]] = temp;
        if(s==t){
            yes;
        }
        else{
            no;
        }
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

