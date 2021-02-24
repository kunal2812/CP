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

void Solution(ll *arr, int N){
    
    cout << endl;
}

int main() {
    int T;
    int i,j,k;
    int N;
    std::cin >> N;
    map<string, int> m;
    for(i=0;i<N;i++){
        string S;
        cin >> S;
        if(m.find(S)==m.end()){
            m[S]++;
            cout << "OK" << endl;
        }
        else{
            string T;
            T = S + to_string(m[S]);
            m[T]++;
            m[S]++;
            cout << T << endl;
        }
    }
    return 0;
}

