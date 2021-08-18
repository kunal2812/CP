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
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

int find(int v, vi parent){
    if(v==parent[v]){
        return v;
    }
    return parent[v] = find(parent[v], parent);
}

void union_set(int x, int y, vi &parent, vi &size){
    int a = find(x, parent);
    int b = find(y, parent);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a]+=size[b];
    }
}


void Solution(){ 
    int n,m1,m2; cin >> n >> m1 >> m2;
    vector<pii> ans;
    vector<vi> adj(n+2, vi(n+2,0));
    vi parent1(n+2), parent2(n+2), size1(n+2), size2(n+2);
    for(int i=1;i<=n;i++){
        parent1[i] = i;  size1[i] = 1;
        parent2[i] = i;  size2[i] = 1;
    }
    for(int i=1;i<=m1;i++){
        int x,y; cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
        union_set(x,y,parent1,size1);
    }
    for(int i=1;i<=m2;i++){
        int x,y; cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
        union_set(x,y,parent2,size2);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(adj[i][j]==0){
                int l3 = find(i, parent1); int m3 = find(j, parent1);
                int l4 = find(i, parent2); int m4 = find(j, parent2);
                if(l3!=m3 && l4!=m4){
                    ans.pb(mp(i,j));
                    union_set(i,j, parent1, size1);
                    union_set(i,j, parent2, size2);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(auto x:ans){
        cout << x.ff << " " << x.sc << endl;
    }
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

