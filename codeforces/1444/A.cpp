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
    ll p,q;
    cin >> p >> q;
    ll ans;
    if((p%q)!=0){
        cout << p << endl; return;
    }
    else{
        ans = p/q;
        if((ans%q)==0){
            ans = 1;
        }
        for(int i=2;i*i<=q;i++){
            if(q%i==0){
                ll t = q/i;
                ll k = p;
                int ct=0;
                while(k%q==0){
                    k/=t;
                    ct++;
                }
                ll cc = pow(t,ct);
                if(cc%q!=0){
                    ans =  max(ans,cc);
                }
                if(k%q!=0){
                    ans =  max(ans,k);
                }
            }
            if(q%i==0){
                ll t = q/i;
                t = q/t;
                ll k = p;
                int ct=0;
                while(k%q==0){
                    k/=t;
                    ct++;
                }
                ll cc = pow(t,ct);
                if(cc%q!=0){
                    ans =  max(ans,cc);
                }
                if(k%q!=0){
                    ans =  max(ans,k);
                }
            }
        }
        ll k =p;
        int ct=0;
        while(k%q==0){
            k/=q;
            ct++;
        }
        ll cc = pow(q,ct);
        if(cc%q!=0){
            ans =  max(ans,cc);
        }
        if(k%q!=0){
            ans =  max(ans,k);
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

