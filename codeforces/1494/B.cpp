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
typedef unordered_map<string, int> umsi;

long long mod = 1000000007;

void Solution(int n, int U, int R, int D , int L){
    for(int i=0;i<16;i++){
        int u = U;
        int r = R;
        int d = D;
        int l = L;
        umsi m;
        int j = i;
        m["ul"] = j%2;
        j/=2;
        m["ur"] = j%2;
        j/=2;
        m["dl"] = j%2;
        j/=2;
        m["dr"] = j%2;
        int w=0,x=0,y=0,z=0;
        if(m["ul"]==1){
            u--;
            l--;
            w=1;
        }
        if(m["ur"]==1){
            u--;
            r--;
            x=1;
        }
        if(m["dl"]==1){
            d--;
            l--;
            y=1;
        }
        if(m["dr"]==1){
            r--;
            d--;
            z=1;
        }
        bool a = min(u,min(r,min(d,l))) >=0;
        bool b = max(u,max(r,max(d,l)))<=(n-2);
        if(a&&b){
            //cout << i << " ";
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    int n;
    int u,r,d,l;
    cin >> T;
    while(T!=0){
        std::cin >> n >> u >> r >> d >>l;
        Solution(n , u ,r ,d ,l);
        T--;
    }
    return 0;
}


