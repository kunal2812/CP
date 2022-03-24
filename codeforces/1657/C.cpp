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
2
01 -> 1 0 
3
011 -> 1 1
4
0000 -> 2 0
5
10001 -> 1 0
6
100010 -> 1 1
*/
void solve(int xx){ 
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    fr(i,0,n,1){
        if((i+1)<n && s[i]==s[i+1]){
            if((i-1)>=0 && s[i-1]!='_'){
                break;
            }
            s[i] = '_'; s[i+1] = '_';
            cnt++; i++;
        }
        else if((i+1)<n && s[i]=='(' && s[i+1]==')'){
            
            if((i-1)>=0 && s[i-1]!='_'){
                break;
            }
            s[i] = '_'; s[i+1] = '_';
            cnt++; i++;
        }
        else{
            if(s[i]==')'){
                
            if((i-1)>=0 && s[i-1]!='_'){
                break;
            }
                int j = i+1;
                while(j<n && s[j]!=')'){
                    j++;
                }
                if(j!=i && s[j]==')'){
                    fr(t,i,j+1,1){
                        s[t] = '_';
                    }
                    cnt++;
                    i = j;
                }
            }
        }
    }
    int r = 0;
    int k = 0;
    while(k<n && s[k]=='_'){
        k++;
    }
    cout << cnt << " " << n-k << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, i=0; 
    cin >> t;
    while(t--)  
        solve(++i);
    return 0;
}
