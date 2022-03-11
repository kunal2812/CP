#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

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
5
1 1
2 2
3 21
4 121
5 212
6 1212
7 12121
8 21212
9 121212
10 1212121
11 2121212
*/
void solve(int xx){ 
    ll n; cin >> n; string ans = "";
    ll sum=0;
    char curr;
    if(n%2){
        curr='2';ans+='1';sum++;
    }
    else{
        curr='1';ans+='2';sum+=2;
    }
    bool l = true;  int i=0;
    while(sum<n){
        if(l){
            ans = curr+ans; 
        }
        else{
            ans+=curr;
            
        }sum+=(curr-'0');
            l=!l;
        i++;
        if(i%2==0){
            if(curr=='2'){
                curr='1';
            }
            else{
                curr='2';
            }
        }
    }
    pr(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
