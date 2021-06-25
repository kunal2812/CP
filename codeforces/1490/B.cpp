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

#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
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


void Solution(){
    int n;
    cin >> n;
    int c[3];
    c[0]=0;
    c[1]=0;
    c[2]=0;
    // cin >> c[0] >> c[1] >> c[2];
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x%3==0){
            c[0]++;
        }
        else if(x%3==1){
            c[1]++;
        }
        else{
            c[2]++;
        }
    }
    int avg = n/3;
    ll ans=0;
    while(c[0]!=c[1] || c[1]!=c[2] || c[0]<avg){
        if(c[0]>c[1]){
            c[1]++;
            c[0]--;
            ans++;
        }
        else if(c[1]>c[2]){
            c[1]--;
            c[2]++;
            ans++;
        }
        else if(c[2]>c[0]){
            c[2]--;
            c[0]++;
            ans++;
        }
    }
    cout << ans << endl; return;
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

