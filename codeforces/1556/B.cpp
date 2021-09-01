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

void Solution(int x){ 
	int n; cin >> n;
	vi o, e;
	for(int i=0;i<n;i++){
		int a;cin >> a;
		if(a%2){
			o.pb(i);
		}
		else{
			e.pb(i);
		}
	}
	int odd = sz(o); int even = sz(e);
	if(abs(odd-even)>1){
		pr(-1);pr(endl);return;
	}
	int j=0; ll s1=0, s2=0; bool f1 = false, f2=false;
	if(even==odd || (even-1)==odd){
		for(int i=0;i<n;i+=2){
			if(j<even){
				s1+=abs(i-e[j]);
			}
			if(j<odd){
				s1+=abs((i+1)-o[j]);
			}
			j++;
		}
		f1=true;
	}
	j=0;
	if(even==odd || (odd-1)==even){
		for(int i=0;i<n;i+=2){
			if(j<odd){
				s2+=abs(i-o[j]);
			}
			if(j<even){
				s2+=abs((i+1)-e[j]);
			}
			j++;
		}
		f2=true;
	}
	if(f1&&f2){
		cout << min(s1, s2)/2 << endl;
	}
	else if(f1){
		pr(s1/2); pr(endl);
	}
	else{
		pr(s2/2);pr(endl);
	}
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



