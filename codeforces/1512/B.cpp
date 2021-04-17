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
    char arr[405][405];
    int a=-1,b=-1,c,d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            if(arr[i][j]=='*' && a==-1){
                a = i;
                b = j;
            }
            if(arr[i][j]=='*' && a!=-1){
                c = i;
                d = j;
            }
        }
    }
    if(a==c && ((a+1)<=n || (c+1)<=n)){
        arr[++a][b] = '*';
        arr[++c][d] = '*';
    }
    if(a==c){
        arr[--a][b] = '*';
        arr[--c][d] = '*';
    }
    if(b==d && ((b+1)<=n || (d+1)<=n)){
        arr[a][++b] = '*';
        arr[c][++d] = '*';
    }
    if(b==d){
        arr[a][--b] = '*';
        arr[c][--d] = '*';
    }
    if(abs(a-d)==abs(b-c)){
        arr[a][d] = '*';
        arr[c][b] = '*';
    }
    if((a-d)==0){
        arr[a][d] = '*';
        arr[c][b] = '*';
    }
    if(d>b || b>d){
        arr[a][d] = '*';
        arr[c][b] = '*';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
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

