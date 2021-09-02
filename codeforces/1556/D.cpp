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

int query(int x, int y, string s){
	int out;
	cout << s << x << " " << y << endl; cout.flush();
	cin >> out;
	return out;
}

void Solution(int x){ 
	int n,k; cin >> n >> k;
	vi a;
	int a12,a23,a13;
	for(int i=1;(i+2)<=n;i+=3){
		a12 = query(i, i+1, "or ")+query(i, i+1, "and ");
		a23 = query(i+1, i+2, "or ")+query(i+1, i+2, "and ");	
		a13 = query(i, i+2, "or ")+query(i, i+2, "and ");
		int a1 = a12+a13-a23; a1/=2; int a3 = a13-a1; int a2 = a23 - a3;
		a.pb(a1); a.pb(a2); a.pb(a3);
	}
	if(n%3==2){
			int a23 = query(n, n-1, "or ")+query(n, n-1, "and ");	
			int a13 = query(n-2, n, "or ")+query(n-2, n, "and ");
			int a1 = a[n-3]; int a3 = a13-a1; int a2 = a23 - a3;
			a.pb(a2); a.pb(a3);
	}
	else if(n%3==1){
		a13 = query(n-2, n, "or ")+query(n-2, n, "and ");
		int a1 = a[n-3]; int a3 = a13-a1;
		a.pb(a3);
	}
	sorta(a);
	cout << "finish " << a[k-1] << endl;  cout.flush(); return;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    int i=0;
    Solution(++i);
    return 0;
}



