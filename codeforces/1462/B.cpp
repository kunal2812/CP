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

void Solution(string s, int N){
    for(int i=0;i<=4;i++){
        if(s.substr(0,i)+s.substr(N-4+i,4-i)=="2020"){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    int i,j,k;
    int N;
    string s;
    cin >> T;
    while(T!=0){
        std::cin >> N;
        cin >> s;
        Solution(s, N);
        T--;
    }
    return 0;
}

