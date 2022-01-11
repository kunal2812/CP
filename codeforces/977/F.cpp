#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
ll m = 1e9 + 7;
int main() {
    fast;
    int n; cin >> n; int a,s;
    map<int, int> m;
    vector<int> nums(n); int l = -1;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        if(m.find(nums[i]-1)!=m.end()){
            m[nums[i]] = max(m[nums[i]],m[nums[i]-1]+1);
        }
        else{
            m[nums[i]] = 1;
        }
        if(m[nums[i]]>ans){
            l = i;
            ans = m[nums[i]];
        }
    }
    cout << ans << endl;
    vector<int> ind; int ele = nums[l];
    for(int j=l; j>=0; j--){
        if(nums[j]==ele){
            ind.push_back(j+1);
            ele--;
        }
    }
    for(int i=ind.size()-1; i>=0; i--){
        cout << ind[i] << " ";
    }cout << endl;
    return 0;
}
