#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first
#define sc second
#define endl '\n'

void Solution(){ 
    int n;
    cin >> n;
    map<int, int> m;
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        m[x]++;
    }
    int ans=0;
    if(m.size()==n){
        ans = 0;
        goto end;
    }
    for(auto t:m){
        int z = t.sc-(n-t.sc);
        ans = max(ans,z);
    }
    end:;
    if(n&1){
        ans = max(1,ans);
    }
    cout << ans << endl;
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