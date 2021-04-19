#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define  IN for(int i=1;i<=n;i++){cin >> a[i];}
#define  OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, vector<int>> umiv;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }


void swap(int *x, int *y)  
{  
    int swap;  
    swap=*x;  
    *x=*y;  
    *y=swap;  
} 

void Solution(){
    int n,q;
    cin >> n >> q;
    vi v;
    umiv m;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        v.pb(a);
    }

    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        int it = find(v.begin(), v.end(), t) - v.begin();
        cout << it+1 << endl;
        while(v[0]!=t){
            swap(v[it], v[it-1]);
            it--;
        }
    }
    // cout << endl;
}

int main() {
    int T;
    Solution();
    return 0;
}

