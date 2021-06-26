#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define in0 for(int i=0;i<n;i++){cin >> a[i];}
#define out0 for(int i=0;i<n;i++){cout << a[i] << " ";}
#define in1 for(int i=1;i<=n;i++){cin >> a[i];}
#define out1 for(int i=1;i<=n;i++){cout << a[i] << " ";}

#define yes cout << "yes" << endl; return;
#define no  cout << "no" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl;

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

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


ll a[1005];
void Solution(){ 
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] = a[i];
    }
    for(int i=0;i<(n-1);i++){
        int x1 = a[i];
        int x2 = a[i+1];
        if(x2<x1){
            swap(x2,x1);
        }
        int dia = x2-x1;
        for(int j=0;j<(n-1);j++){
            if(i==j){
                continue;
            }
            int y1= a[j];
            int y2= a[j+1];
            if(y2<y1){
                swap(y2,y1);
            }
            if(y1>x1 && y1<x2){
                if(y2>x2){
                    yes;
                }
            }
        }
    }
    no;
}

int main() {
    fast;
    // int T;
    // cin >> T;
    // while(T!=0){
        Solution();
    //     T--;
    // }
    return 0;
}

