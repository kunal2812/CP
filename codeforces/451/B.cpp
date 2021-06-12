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
    int n;
    cin >> n;
    ll a[100005];
    ll b[100005];
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    bool s = true;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            s=false;
            break;
        }
    }
    if(s==true){
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl; return;
    }
    int l=-1;int r=-1;
    int segct = 0;
    int ansl=-1;
    int ansr=-1;
    for(int i=0;i<(n-1);i++){
        if(a[i]>a[i+1]){
            if(l==-1){
                l=i;
            }
            ansl = l;
            r=i+1;
            ansr = r;
        }
        else{
            if(l!=-1){
                segct++;
                l=-1;
                r=-1;
            }
            if(segct==2){
                cout << "no" << endl; return;
            }
        }
    }
    if(ansl==-1 && ansr==-1){
        cout << "no" << endl; return;
    }
    int i = ansl;
    int j = ansr;
    while(i<j){
        swap(a[i], a[j]);
        i++;
        j--;
    }
    bool t = true;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            t=false;
            break;
        }
    }
    if(t==true){
        cout << "yes" << endl;
        cout << ++ansl << " " << ++ansr << endl; return;
    }
    cout << "no" << endl; return;
}

int main() {
    fast;
    Solution();
    return 0;
}

