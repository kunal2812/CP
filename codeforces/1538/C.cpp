#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl;


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
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

ll mod = 1000000007;


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

int lowerIndex(ll arr[], int n, ll x, int i)
{
    int l = i, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] >= x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
 
// function to find last index <= y
int upperIndex(ll arr[], int n, ll y, int i)
{
    int l = i, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] <= y)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}
 
// function to count elements within given range
int countInRange(ll arr[], int n, ll x, ll y, int i)
{
    // initialize result
    int count = 0;
    count = upperIndex(arr, n, y, i) - lowerIndex(arr, n, x, i) + 1;
    return count;
}

void Solution(){
    ll n,l,r;
    cin >> n >> l >> r;
    ll a[200005];
    ll b[200005];
    umii m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    ll count=0;
    for(int i=0;i<n;i++){
        int t = countInRange(a, n, l-a[i], r-a[i], i+1);
        // cout << a[i] << " " << t << endl;
        count+=t;
    }
    cout << count << endl;
}

int main() {
    fast;
    int T;
    cin >> T;
    while(T!=0){
        Solution();
        T--;
    }
    return 0;
}

