#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
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

void swapp(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void Solution(){
    int n,x;
    int a[150];
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==x && (i-1)>=0){
            swapp(a[i], a[i-1]);
        }
        if(sum==x && (i+1)<n){
            sum-=a[i];
            sum+=a[i+1];
            swapp(a[i], a[i+1]);
        }
    }
    sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==x){
            no;
        }
    }
    cout << "YES" <<  endl;
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
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

