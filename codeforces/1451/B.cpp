#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=0;i<n;i++){cin >> a[i];}
#define OUT for(int i=0;i<n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl; 
#define dc double
#define ff first
#define sc second

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

ll mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q--){
        int l,r;
        cin >> l >>r;
        --l,--r;
        bool f1=true;
        for(int i=0;i<l;i++){
            if(s[i]==s[l]){
                f1 = false;
            }
        }
        for(int i=r+1;i<n;i++){
            if(s[i]==s[r]){
                f1=false;
            }
        }
        if(f1){
            no;
        }
        else{
            yes;
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

