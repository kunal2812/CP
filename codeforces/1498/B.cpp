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
ll a[100005];
void Solution(){
    ll n,w;
    cin >> n >> w;
    int ct=1;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    int sum=w;
    while(s.empty()!=true){
        auto it = s.upper_bound(sum);
        auto ee = s.end();
        int ub;
        if(it==ee){
            --ee;
            ub = *ee;
        }
        else{
            --it;
            ub =  *it;
        }
        if((sum-ub)>0){
            if(s.find(ub)!=s.end()){
                s.erase(s.find(ub));
            }
            sum-=ub;
        }
        else if((sum-ub)==0){
            if(s.find(ub)!=s.end()){
                s.erase(s.find(ub));
            }
            sum-=ub;
            if(s.empty()!=true){
                ct++;
                sum=w;
            }
        }
        else{
            ct++;
            sum=w;
        }
        // cout << sum << " " << ct << endl;
    }
    cout << ct << endl;
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

