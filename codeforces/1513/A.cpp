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
    int n, k;
    cin >> n >>k;
    int t = ceil((double)n/2) - 1;
    if(t<k){
        cout << -1 << endl;
        return;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    int c=0;
    int i=2;
    int arr[120];
    arr[1] = 1;
    while(c!=k){
        if(i%2==1){
            arr[i] = i-1;
        }
        else{
            arr[i] = i+1;
            c++;
        }
        i++;
    }
    arr[i] = i-1;
    for(int j=i+1;j<=n;j++){
        arr[j] = j;
    }
    for(int j=1;j<=n;j++){
        cout << arr[j] << " ";
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

