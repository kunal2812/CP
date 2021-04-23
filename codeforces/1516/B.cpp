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
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

ll mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    int n;
    ll a[2005];
    cin >> n;
    IN;
    ll x = 0;
    int y=1;
    for(int i=0;i<(n-1);i++){
        if(a[i]!=a[i+1]){
            y=0;
            break;
        }
    }
    // cout << y<< endl;
    if(y==1){
        yes;
    }
    for(int i=0;i<n;i++){
        x^=a[i];
    }
    if(x==0){
        yes;
    }
    else{
        int k=0;
        int c=0;
        for(int i=0;i<n;i++){
            k^=a[i];
            if(k==x){
                c++;
                k=0;
            }
        }
        if(c>2){
            yes;
        }
        no;
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

