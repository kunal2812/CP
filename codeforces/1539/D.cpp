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
struct item{
    ll a,b;
};
bool cmp(item x, item y){
    if(x.b==y.b){
        return x.a>y.a;
    }
    return x.b<y.b;
}
void Solution(){
    int n;
    cin >> n;
    item arr[100005];
    ll items = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i].a >> arr[i].b;
        items+=arr[i].a;
    }
    sort(arr+1, arr+n+1, cmp);
    // for(int i=1;i<=n;i++){
    //     cout << arr[i].a << " ";
    // }nl;
    // for(int i=1;i<=n;i++){
    //     // cout << arr[i].b << " ";
    // }
    // nl;
    int i=1;
    int j=n;
    ll curr=0;
    ll cc=0;
    while(i<=j && i<=n && j>=1){
        if(arr[i].b<=cc){
            curr+=arr[i].a;
            cc+=arr[i].a;
            arr[i].a=0;
            // cout << i << " " << j << " " << curr << " " << cc << endl;
            i++;
        }
        else{
            ll diff = abs(cc-arr[i].b);
            cc+=diff; curr+=(2*diff); arr[j].a-=diff;
            // cout << i << " " << j << " " << curr << " " << cc << endl;
            if(arr[j].a==0){
                j--;
            }
        }
    }
    curr = min(2*items, curr);
    cout << curr << endl;
}

int main() {
    fast;
    // int T;
    // cin >> T;
    // while(T!=0){
        Solution();
    //     T--;
    // }
    return 0;
}

