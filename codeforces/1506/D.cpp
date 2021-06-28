#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first
#define sc second
#define endl '\n'

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void Solution(){ 
    int n;
    cin >> n;
    unordered_map<int, int, custom_hash> m;
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