#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
typedef map<int,int> mii;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umii;

typedef unordered_set<int> usi;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x << endl

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())
#define gtmin(a) *min_element(a.begin(), a.end())

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

ll mod = 1000000007;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
/*
2
1 2 T

1
1

3
1 2 y
1 3 x
2 3 y
-1 1 -1 

4
1 2 1
1 3 0
1 4 -1
2 3 1
2 4 0
3 4 1

1 4
2 1
3 4
4 1

5
1 2 y
1 3 x
1 4 y
1 5 x
2 3 y
2 4 x
2 5 y
3 4 x
3 5 y
4 5 x

1 6
2 6
3 6
4 6
5 6

6
1 2 x
1 3 x
1 4 y
1 5 y
1 6 T
2 3 x
2 4 x
2 5 y
2 6 y
3 4 T
3 5 x
3 6 x
4 5 y
4 6 y
5 6 T

7
1 7
2 7
3 7
4 7
5 7
6 7
*/
void solve(int xx){ 
    int n; cin >> n;
    if(n%2==1){
        // pr((n/2)*3);
        fr(i,0,(n*(n-1))/2,1){
            if(i%2==0){
                cout << -1 << " ";
            }
            else{
                cout << 1 << " ";
            }
        }nl;
    }
    else{
        fr(i,1,n+1,1){
            fr(j,i+1,n+1,1){
                if((j-i)==n/2){
                    cout << 0 << " ";
                }
                else if((j-i)<(n/2)){
                    cout << 1 << " ";
                }
                else{
                    cout << -1 << " ";
                }
            }
        }nl;
        /*
        1 2 x
        1 3 x
        1 4 x
        1 5 T
        1 6 y
        1 7 y
        1 8 y
        2 3 x
        2 4 x
        2 5 x
        2 6 T
        2 7 y
        2 8 y
        3 4 y
        3 5 x
        3 6 x
        3 7 x
        3 8 y
        4 5 y
        4 6 y
        4 7 T
        4 8 x
        5 6 x
        5 7 x
        5 8 y
        6 7 y
        6 8 y
        7 8 T
        */
    }
}

int main() {
    fast;
    int t, i=0; cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
