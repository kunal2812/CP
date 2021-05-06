#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
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

void Solution(){
    int n;
    cin >> n;
    if(n==2){
        cout << -1 << endl; return;
    }
    if(n==3){
         cout << "2 9 7\n4 6 3\n1 8 5" << endl; return;
    }
    int count=0;
    int a[110][110];
    for(int i=1;i<=n;i++){
        a[i][i] = ++count;
    }
    int i = 1;
    int j = i+1; 
    int k = n;
    int t=2;
    while(i<=k){
        while(j<=n){
            if(i!=j){
                a[i][j] = ++count;
            }
            i++;
            j++;
        }
        k--;
        i = 1;
        j=++t;
    }
    i=2;
    j=i-1;
    k=n;
    t=2;
    while(j<=k){
        while(i<=n){
            if(i!=j){
                a[i][j] = ++count;
            }
            i++;
            j++;
        }
        k--;
        j=1;
        i = ++t;
    }
    int tx = a[n][1];
    a[n][1] = a[1][n];
    a[1][n] = tx;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
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

