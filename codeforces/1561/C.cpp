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

#define sorta(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define rev(s) reverse(s.begin(), s.end())

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vi> umiv;
// m.reserve(1024);
// m.max_load_factor(0.25);
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(a) a.size()
#define pr(x) cout << x

#define ctset(n) __builtin_popcountll(n)
#define ctunset(n) __builtin_ctzll(x)
#define gtmax(a) *max_element(a.begin(), a.end())

#define printA(a) for(auto x:a){ cout << x << " "; }nl;
// To rotate an array
// rotate(v.begin(), v.end()+k, v.end())

// To fill consecutive values in a vector
// iota(all(v),1);

// For problem involving precision
// cout << fixed << setprecision(10) << xx+mx << endl;

ll mod = 1000000007;

struct item{
	int first,second;
};
bool cmp(item x, item y){
	return x.ff<y.ff;
}

void Solution(int x){ 
    int n; cin >> n;
    vector<vector<int>> v(n);
    vector<item> temp(n);
    for(int i=0;i<n;i++){
    	int x; cin >> x;
    	int maxP = 0;
    	for(int j=0;j<x;j++){
    		int y; cin >> y;
    		maxP = max(maxP, y-j);
    		v[i].pb(y);
    	}
    	temp[i].ff = maxP;
    	temp[i].sc = i;
    }
    sort(all(temp), cmp);
	int ans = 0;
	int t=0; 
	int p = temp[0].sc;
	ans = v[p][0]+1;
	for(int i=0;i<n;i++){
		int p = temp[i].sc;
		// pr(p);pr(endl);
		for(int j=0;j<sz(v[p]);j++){
			if((ans+t)<=v[p][j]){
				ans = v[p][j]-t+1;
			}
			t++;
		}
		// pr(ans);
	}
	cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    int T;
    cin >> T;
    int i=0;
    while(T!=0){
        Solution(++i);
        T--;
    }
    return 0;
}



