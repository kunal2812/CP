#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define endl '\n'
#define nl cout << '\n';

typedef vector<int> vi;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    fast;
    int n, m; cin >> n >> m;
    set<int> s;
    fr(i,1,n+1,1){
        s.insert(i);
    }
    vi ans(n+1, 0);
    int l,r,x; 
    fr(i,1,m+1,1){
        cin >> l >> r >> x;
        auto itr = s.lower_bound(l);
        vector<int> v;
        while(itr!=s.end()){
            int cur = *itr;
            if(cur>r){
                break;
            }
            if(cur!=x){
                ans[cur] = x;
                v.pb(cur);
            }
            itr++;
        }
        for(auto x:v){
            s.erase(x);
        }
    }
    fr(i,1,n+1,1){
        cout << ans[i] << " ";
    }nl;
    return 0;
}