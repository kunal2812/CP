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

void Solution(int N, int* A){
    unordered_map<int, vector<int>> m;
    m[0].pb(1);
    int count = 1000;
    //while(count){
        for(int i=0;i<N-1;i++){
            //if(m.find(A[i])!=m.end()){
                m[A[i]].pb(i+2);
            //}
        }
        //count--;
    //}
    int y=1;
    /*for(int i=0;i<N;i++){
        int n = m[i].size();
        for(int j=0;j<n;j++){
            cout << i << " " << m[i][j] << endl;
        }
    }*/
    
    for(int i=1;i<=N;i++){
        if(m[i].size()!=0){
            int n = m[i].size();
            int count=0;
            int j;
            for(j=0;j<n;j++){
                //cout << i << " " << j << " " << m[i][j] << endl;
                if(m[m[i][j]].size()==0){
                    count++;
                }
            }
            //cout << m[i][j] << " " << count << endl;
            if(count<3){
                y=0;
                break;
            }
        }
    }
    if(y==1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    int i,j;
    int N;
    int A[300000];
        std::cin >> N;
        for(i=0;i<N-1;i++){
            cin >> A[i];
        }
        Solution(N,A);
    return 0;
}

