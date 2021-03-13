#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;

long long mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

void Solution(){
    int n;
    cin >> n;
    int a[200005];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    unordered_map<int, pair<int, int>> m;
	    
	    for(int i = 0;i<n;i++){
	        for(int j = i+1; j < n;j++){
	            int sum = a[i]+a[j];
	            if(m.find(sum) == m.end()){
	                m[sum] = mp(i,j);
	            }
	            else{
	                pair<int,int> p = m[sum];
	                // flag = 1;
	                if((p.first!=i && p.second!=j) && (p.first!=j && p.second!=i)){
    	                cout << "YES" << endl;
    	                cout << p.first + 1 << " " << p.second + 1 << " " << i+1 << " " << j+1 <<endl; return;
	                }
	            }
	        }
	    }
	cout << "NO" << endl;
}

int main() {
        Solution();
    return 0;
}

