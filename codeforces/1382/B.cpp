#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=0;i<n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
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
    ll n;
    cin >> n;
    ll a[100005];
    IN;
    int i=1;
    bool y = true;
    int c=0;
    while(a[i]==1 && i<=n){
        c++;
        i++;
    }
    if(c==0 || n==1){
        cout << "First" << endl;
    }
    else if(n==c && c%2==0){
        cout << "Second" << endl;
    }    
    else if(n==c && c%2==1){
        cout << "First" << endl;
    }
    // cout << c << endl;
    else if(c%2==0){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
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

