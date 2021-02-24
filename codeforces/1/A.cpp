#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define db (double)
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;

long long mod = 1000000007;


int main() {
    ll n,m,a;
    cin >> n >>m >> a;
    ll ans = ceil(db m/a)*ceil(db n/a);
    cout << ans << endl;
    return 0;
}

