#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;

long long mod = 1000000007;



int main() {
    int T;
    int i,j,k;
    int N;
    int a[100005];
    int n,q;
    cin >> n >> q;
    int c0=0, c1=0;
    for(i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==0){
            c0++;
        }
        else{
            c1++;
        }
    }
    // cout << c0 << c1 << endl;
    while(q!=0){
        int t,r;
        cin >> t >> r;
        if(t==1){
            a[r-1] = 1-a[r-1];
            if(a[r-1]==0){
                c0++;
                c1--;
            }
            else{
                c1++;
                c0--;
            }
        }
        else{
            if(r>c1){
                cout << 0 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
        q--;
    }
    return 0;
}

