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

void Solution(){
    int n;
    cin >> n;
    vector<int> odd;
    vector<int> even;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        if(k%2==0){
            even.pb(k);
        }
        else{
            odd.pb(k);
        }
    }
    for(int i=0;i<odd.size();i++){
        cout << odd[i] <<" ";
    }
    for(int i=0;i<even.size();i++){
        cout << even[i] <<" ";
    }
    cout << endl;
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

