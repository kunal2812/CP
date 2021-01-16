#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef pair<int, int> pii;

void Solution(ll *arr, int N){
    int count1=0;
    int count2=0;
    int sum=0;
    for(int i=0;i<N;i++){
        if(arr[i]==1){
            count1++;
        }
        if(arr[i]==2){
            count2++;
        }
        sum+=arr[i];
    }
    //cout << sum << endl;
    if(sum%2==1){
        cout << "NO" << endl;
        return;
    }
    if(sum%2==0){
        int half = sum/2;
        //cout << count1 << "   " << count2 << "    " << half/2 << "    " <<  half-((half/2)*2) << endl;
        if(half%2==0 || (half%2==1 && count1!=0)){
            cout << "YES" << endl;
            return;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

int main() {
int T;
int i,j,k;
int N;
long long A[100000];
cin >> T;
while(T!=0){
    std::cin >> N;
    for(i=0;i<N;i++){
        cin >> A[i];
    }
    Solution(A, N);
    T--;
}
return 0;
}

