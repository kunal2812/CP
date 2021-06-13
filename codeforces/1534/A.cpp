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

void Solution(){
    int n,m;
    cin >> n >> m;
    char arr[100][100];
    char ans1[100][100];
    
    char ans2[100][100];
    int red = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                if(j%2==1)
                    ans1[i][j] = 'R';
                else
                    ans1[i][j] = 'W';
            }
            else{
                if(j%2==1)
                    ans1[i][j] = 'W';
                else
                    ans1[i][j] = 'R';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                if(j%2==0)
                    ans2[i][j] = 'R';
                else
                    ans2[i][j] = 'W';
            }
            else{
                if(j%2==0)
                    ans2[i][j] = 'W';
                else
                    ans2[i][j] = 'R';
            }
        }
    }

    // if(f1){
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<m;j++){
            //         cout << ans1[i][j];
            //     }
            //     cout << endl;
            // }
        // }
        // else{
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<m;j++){
            //         cout << ans2[i][j];
            //     }
            //     cout << endl;
            // }
        // }
    bool f1=true;
    bool f2 = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!='.' && arr[i][j]!=ans1[i][j]){
                f1 = false;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!='.' && arr[i][j]!=ans2[i][j]){
                f2 = false;
            }
        }
    }
    if(!f1 && !f2){
        no;
    }
    else{
        cout << "YES" << endl;
        if(f1){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout << ans1[i][j];
                }
                cout << endl;
            }
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout << ans2[i][j];
                }
                cout << endl;
            }
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

