#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl cout << endl;

typedef vector<int> vi;

int lt[200005];
int rt[200005];
void Solution(){ 
    int n,m; 
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int j=0;
    for(int i=0;i<n;i++){
        if(s[i]==t[j]){
            lt[j] = i;
            j++;
        }
    }
    j = m-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]==t[j]){
            rt[j] = i;
            j--;
        }
    }
    int ans=0;
    for(int i=1;i<m;i++){
        ans = max(ans, abs(rt[i]-lt[i-1]));
    }
    cout << ans << endl;
}

int main() {
    fast;
    Solution();
    return 0;
}

