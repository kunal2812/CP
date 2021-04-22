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

ll mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void Solution(){
    int n;
    cin >> n;
    int a[200005];
    IN;
    vector<int> v1, v2;
    usi s;
    for(int i=1;i<=n;i++){
        s.insert(a[i]);
        if(a[i]==0){
            v1.pb(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(s.find(i)==s.end()){
            v2.pb(i);
        }
    }
    for(int i=0;i<(v1.size());i++){
        // cout << v1[i] << " " << v2[i] << endl;
        if(v1[i]==v2[i]){
            int t = v2[i];
            if((i+1)>=(v1.size())){
                v2[i] = v2[0];
                v2[0] = t;
                // cout << v2[i] << " " << v2[0] << endl;
            }
            else{
                // cout << v2[i] << " " << v2[i+1] << endl;
                v2[i] = v2[i+1];
                v2[i+1] = t;
                // cout << "DD" << endl;
                // cout << v2[i] << " " << v2[i+1] << endl;
            }
        }
    }
    for(int i=0;i<(v1.size());i++){
        a[v1[i]] = v2[i];
    }
    OUT;
    cout << endl;
}

int main() {
    fast;
        Solution();
    return 0;
}

