#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define IN for(int i=1;i<=n;i++){cin >> a[i];}
#define OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}
#define yes cout << "YES" << endl; return;
#define no  cout << "NO" << endl; return;
#define dc double
#define ff first
#define sc second
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


// for(int i=0;i<n;i++){
//     cin >> a[i];
// }

int lps(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi[n-1];
}

void Solution(){
    string s,t;
    cin >> s >> t;
    if(s.length()<t.length()){
        cout << s << endl; return;
    }
    // cout << lps(t) << endl;
    string pref = t.substr(0, lps(t));
    // cout << pref << endl;
    int cts1=0,cts0=0,ctt1=0,ctt0=0,cp1=0,cp0=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            cts1++;
        }
        else{
            cts0++;
        }
    }
    for(int i=0;i<t.length();i++){
        if(t[i]=='1'){
            ctt1++;
        }
        else{
            ctt0++;
        }
    }
    for(int i=0;i<pref.length();i++){
        if(pref[i]=='1'){
            cp1++;
        }
        else{
            cp0++;
        }
    }
    if(cts1<ctt1 || cts0<ctt0){
        cout << s << endl; return;
    }
    string ans=t;
    cts1-=ctt1;
    cts0-=ctt0;
    int ind = pref.length();
    string add = t.substr(ind, t.length()-ind);
    // if(t.length()==1){
    //     add = pref;
    //     cp1 = 0;
    //     cp0 = 0;
    // }
    // cout << add << endl;
    while(cts1>=(ctt1-cp1) && cts0>=(ctt0-cp0)){
        ans+=add;
        cts1-=(ctt1-cp1);
        cts0-=(ctt0-cp0);
    }
    while(cts1>0){
        ans+='1';
        cts1--;
    }
    while(cts0>0){
        ans+='0';
        cts0--;
    }
    cout << ans << endl;
}

int main() {
    fast;
    Solution();
    return 0;
}

