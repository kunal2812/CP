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

void Solution(int *p, int n){
    int ans[200005];
    for(int i=0;i<=n;i++){
        ans[i]=0;
    }
    unordered_set<int> s;
    for(int i=1;i<=n;i++){
        if(s.find(i)==s.end()){
            int count=1;
            int j=p[i];
            vector<int> path;
            path.pb(i);
            while(i!=j){
                path.pb(j);
                j = p[j];
                count++;
            }
            for(int i=0;i<path.size();i++){
                ans[path[i]]=count;
                s.insert(path[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    int i,j,k;
    int N;
    int P[200005];
    cin >> T;
    while(T!=0){
        std::cin >> N;
        P[0]=0;
        for(i=1;i<=N;i++){
            cin >> P[i];
        }
        Solution(P, N);
        T--;
    }
    return 0;
}

