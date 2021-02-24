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

int next(int arr[], int target, int end)  
{  
    int start = 0;  
  
    int ans = -1;  
    while (start <= end)  
    {  
        int mid = (start + end) / 2;  
  
        // Move to the left side if the target is smaller  
        if (arr[mid] > target)  
        {  
            end = mid - 1;  
        }  
  
        // Move right side  
        else 
        {  
            ans = mid;  
            start = mid + 1;  
        }  
    }  
    return ans;  
}  

void Solution(int *x, int n){
    sort(x, x+n);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int m; cin >> m;
        int index = next(x,m, n-1);
        if(index==-1){
            cout << 0 << endl;
        }
        else{
            cout << index+1 << endl;
        }
    }
}

int main() {
    int T;
    int i,j,k;
    int N;
    int X[100009];
    cin >> N;
    for(i=0;i<N;i++){
        cin >> X[i];
    }
    Solution(X, N);
    return 0;
}

