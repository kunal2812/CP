#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl;

int query(int t){
    cout << t << endl; cout.flush();
    int x;
    cin >> x;
    return x;
}
void Solution(){ 
    int n,k; cin >> n >> k;
    int q = -1;
    int i = 0;
    while(q!=1){
        if(i==0){
            q = query(i);
        }
        else{
            q = query(i^(i-1));
        }
        i++;
    }
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

