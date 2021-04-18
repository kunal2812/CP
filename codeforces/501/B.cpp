#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define  IN for(int i=1;i<=n;i++){cin >> a[i];}
#define  OUT for(int i=1;i<=n;i++){cout << a[i] << " ";}

typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unordered_map<char, int> umci;
typedef unordered_map<string, int> umsi;

long long mod = 1000000007;


void Solution(){
    int q;
    cin >> q ;
    bool vis[1005];
    string child[1005];
    unordered_map<string, string> m;
    for(int i=0;i<q;i++){
        string a,b;
        cin >> a >> b;
        m[b] = a;
        child[i]=b;
    }
    unordered_map<string, string> ans;
    unordered_map<string, int> ind;
    for(int i=0;i<q;i++){
        vis[i] = false;
        ind[child[i]] = i;
    }
    for(int i=q-1;i>=0;i--){
        if(!vis[i]){
            // cout << child[i] << endl;
            string p = m[child[i]];
            if(m.find(p)!=m.end()){
                vis[ind[p]]=true;
            }
            // cout << ind[p] << endl;
            while(m.find(p)!=m.end()){
                p = m[p];
                if(m.find(p)!=m.end()){
                    vis[ind[p]]=true;
                }
            }
            ans[child[i]] = p;
        }
    }
    cout << ans.size() << endl;
    unordered_map<string,string>::iterator itr;
    for(itr = ans.begin();itr!=ans.end();itr++){
        cout << itr->second << " " << itr->first << endl;
    }
}

int main() {
    int T;
    Solution();
    return 0;
}

