#pragma GCC optimize("Ofast")  
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define endl '\n'
#define nl cout << endl;
typedef vector<ll> vll;

ll table[200005][18];

ll query(int l, int r){
    if(l>r){
        swap(l,r);
    }
    int length = log2(abs(r-l+1));
    return __gcd(table[l][length], table[r-(1<<length)+1][length]);
}

void Solution(){ 
    int n; cin >> n;
    vll a(n), d(n-1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<(n-1);i++){
        d[i] = abs(a[i]-a[i+1]);
        table[i][0] = d[i];
    }
    int maxPow = log2(n-1);
    for(int j=1;j<=maxPow;j++){
        for(int i=0;(i+(1<<j)+1)<=n;i++){
            table[i][j] = __gcd(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
    // for(int i=0;i<d.size();i++){
    //     for(int j=0;j<=maxPow;j++){
    //         cout << table[i][j] << " ";
    //     }nl;
    // }
    int ans=0; int j=0;
    for(int i=0;i<d.size();i++){
        // cout << i << " " << j << " " << query(i,j) << endl;
        while(j<=i && query(i,j)==1){
            j++;
        }
        ans = max(ans,i-j+2);
    }
    cout << max(ans,1) << endl;
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
 