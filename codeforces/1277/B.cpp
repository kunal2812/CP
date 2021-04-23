#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=0;i<n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double

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

void Solution(){
    int n;
    cin >> n;
    set<ll, std::greater<ll>> s;
    for(int i=0;i<n;i++){
        ll t;
        cin >> t;
        if(t%2==0){
            s.insert(t);
        }
    }
    set<ll, std::greater<ll>>::iterator itr, newitr;
    itr = s.begin();
    int c=0;
    while(s.empty()!=true){
        while(itr!=s.end()){
            ll d = (*itr)/2;
            // cout << *itr << " " << d << endl;
            s.erase(itr);
            if(d%2==0) s.insert(d);
            // cout << *itr << endl;
            itr = s.begin();
            c++;
        }
    }
    cout << c <<  endl;
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

