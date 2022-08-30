#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front

#define yes cout << "YES" << endl; return
#define no  cout << "NO" << endl; return

#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os; // find_by_order, order_of_key
typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> oms; // ordered_multiset
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

/*

*/

int dx[] = {1,0,-1,0,1,-1,-1,1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

bool isValid(int x, int y, int n, int m){
    if(x<0 || y<0 || x>=n || y>=m){
        return false;
    }
    return true;
}

int count(int x, int y, vector<string> &a){
    int cnt = 0;
    fr(i,0,4,1){
        int X = x+dx[i];
        int Y = y+dy[i];
        if(isValid(X,Y,a.size(),a[0].size()) && a[X][Y]=='*'){
            cnt++;
        }
    }
    return cnt;
}

int count2(int x, int y, vector<string> &a){
    int cnt = 0;
    fr(i,4,8,1){
        int X = x+dx[i];
        int Y = y+dy[i];
        if(isValid(X,Y,a.size(),a[0].size()) && a[X][Y]=='*'){
            cnt++;
        }
    }
    return cnt;
}

void solve(int xx){ 
    int n,m; cin >> n >> m;
    vector<string> a(n);
    fr(i,0,n,1){
        cin >> a[i];
    }
    fr(i,0,n,1){
        fr(j,0,m,1){
            if(a[i][j]=='*'){
                if(count(i,j,a)==0){
                    no;
                }
                else if((j+2)<m && a[i][j+1]=='*' && a[i][j+2]=='*'){
                    no;
                }
                else if((i+2)<n && a[i+1][j]=='*' && a[i+2][j]=='*'){
                    no;
                }
                else if((i+1)<n && a[i+1][j]=='*' && count(i,j,a)==1 && count(i+1,j,a)==1){
                    no;
                }
                else if((i-1)>=0 && a[i-1][j]=='*' && count(i-1,j,a)==1 && count(i,j,a)==1){
                    no;
                }
                else if((j-1)>=0 && a[i][j-1]=='*' && count(i,j-1,a)==1 && count(i,j,a)==1){
                    no;
                }
                else if((j+1)<m && a[i][j+1]=='*' && count(i,j+1,a)==1 && count(i,j,a)==1){
                    no;
                }
                else if(isValid(i,j-1,n,m) && isValid(i+1,j,n,m) && a[i][j-1]=='*' && a[i+1][j]=='*'){
                    if(count(i,j-1,a)!=1 || count(i+1,j,a)!=1 || count(i,j,a)!=2 || count2(i,j,a)!=0 || count2(i,j-1,a)!=1 || count2(i+1,j,a)!=1){
                        no;
                    }
                }
                else if(isValid(i,j+1,n,m) && isValid(i+1,j,n,m) && a[i][j+1]=='*' && a[i+1][j]=='*'){
                    if(count(i,j+1,a)!=1 || count(i+1,j,a)!=1 || count(i,j,a)!=2 || count2(i,j,a)!=0 || count2(i,j+1,a)!=1 || count2(i+1,j,a)!=1){
                        no;
                    }
                }
                
                else if(isValid(i-1,j,n,m) && isValid(i,j+1,n,m) && a[i-1][j]=='*' && a[i][j+1]=='*'){
                    if(count(i-1,j,a)!=1 || count(i,j+1,a)!=1 || count(i,j,a)!=2 || count2(i,j,a)!=0 || count2(i-1,j,a)!=1 || count2(i,j+1,a)!=1){
                        no;
                    }
                }
                
                else if(isValid(i-1,j,n,m) && isValid(i,j-1,n,m) &&a[i-1][j]=='*' && a[i][j-1]=='*'){
                    if(count(i-1,j,a)!=1 || count(i,j-1,a)!=1 || count(i,j,a)!=2 || count2(i,j,a)!=0 || count2(i-1,j,a)!=1 || count2(i,j-1,a)!=1){
                        no;
                    }
                }
            }
        }
    }
    yes;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
