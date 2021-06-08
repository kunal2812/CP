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
 
unordered_set<string> subString(string str, int n)
{
    // Pick starting point
    unordered_set<string> m;
    for (int len = 1; len <= n; len++)
    {   
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point. 
            int j = i + len - 1;
            string h = "";
            for (int k = i; k <= j; k++)
                h+=str[k];
             
            m.insert(h);
        }
    }
    return m;
}
 
void Solution(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    unordered_set<string> m = subString(s, n);
    string ans = "";
    while(true){
        if(ans.length()==0 || ans[0]=='z'){
            for(int i=0;i<ans.length();i++){
                ans[i]='a';
            }
            ans+=char('a'-1);
        }
        int j = ans.length()-1;
        for(int i=j;i>=0;i--){
            if(ans[i]<122){
                ans[i] = char(++ans[i]);
                // cout << ans << endl;
                if(m.find(ans)==m.end()){
                    cout << ans << endl; return;
                }
                break;
            }
            if(ans[i]=='z'){
                for(int k=i;k<=j;k++){
                    ans[k]='a';
                }
            }
        }
    }
    // cout << ans << endl;
 
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