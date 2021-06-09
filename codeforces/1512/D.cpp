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
    ll a[200005];
    ll sum=0;
    unordered_map<ll, int> s;
    for(int i=0;i<(n+2);i++){
        ll x;
        cin >> x;
        a[i]=x;
        s[x]++;
        sum+=x;
    }
    sort(a, a+n+2);
    ll m1 = a[n+1];
    ll m2 = a[n];
    unordered_map<ll, int>::iterator it;
    // cout << sum-(2*m1) << " " << sum-(2*m2) << endl;
    
    ll t1 = sum - (2*m1);
    ll t2 = sum - (2*m2);
    if(s.find(t1)!=s.end()){
        ll t = sum - (2*m1);
        if(t==m1 && s[m1]>1){
            s[t]--;
            s[m1]--;
            for(it=s.begin();it!=s.end();it++){
                for(int i=0;i<it->sc;i++){
                    cout << it->ff << " ";
                }
            }
            cout << endl; return;
        }
        else if(t!=m1){
            s[t]--;
            s[m1]--;
            for(it=s.begin();it!=s.end();it++){
                for(int i=0;i<it->sc;i++){
                    cout << it->ff << " ";
                }
            }
            cout << endl; return;
        }
    }
    if(s.find(t2)!=s.end()){
        ll t = sum - (2*m2);
        if((t==m2 && s[m2]>1) || t!=m2){
            s[t]--;
            s[m2]--;
            for(it=s.begin();it!=s.end();it++){
                for(int i=0;i<it->sc;i++){
                    cout << it->ff << " ";
                }
            }
            cout << endl; return;
        }
    }
    cout << -1 << endl;
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

