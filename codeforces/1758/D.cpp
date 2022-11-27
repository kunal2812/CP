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
#define nl cout << '\n'

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef map<int,int> mii;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os; // find_by_order, order_of_key (#less than key)
typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> oms; // ordered_multiset
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

#define scn(x) cin >> x
#define scna(x,a,b) for(int i=a; i<=b; i++){cin >> x[i];}
#define pr(x) cout << x << endl
#define pra(a) for(auto x:a){cout << x << " ";}nl

ll mod = 1000000007;

/*
8: 16 22 23 24 25 26 29 30
*/
int a[300005];
void solve(int xx){ 
    int n; scanf("%d",&n);
    ll pp; int c;
    if(n==2){
        printf("1 3\n");
    }
    else if(n==3){
        printf("3 6 7\n");
    }
    else{
        a[1] = 2*(n-1);
        a[n] = a[1]+2*(n-1);
        top:;
        pp = (a[n]-a[1]); pp*=pp;
        pp-=(a[1]+a[n]);
        c = 1;
        rfr(i,n-1,2,1){
            a[i] = a[n]-c++;
            pp-=a[i];
        }
        if(pp>0){
            a[1]+=(n/2);
            a[n]+=(n/2);
            goto top;
        }
        fr(i,2,n,1){
            c = min(pp*-1,(ll)a[i]-a[i-1]-1);
            a[i]-=c;
            pp+=c;
        }
        fr(i,1,n+1,1){
            printf("%d ",a[i]);
        }printf("\n");
        // printf("%d\n",pp);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    scanf("%d",&t);
    while(t--)  
        solve(++i);
    return 0;
}
