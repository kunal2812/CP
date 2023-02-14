#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define LOG 19

vector<int> G[N];
int dp[N], L[N];
int LCA[N][LOG+1];

int dfs(int x, int lvl, int p){
    LCA[x][0] = p;
    L[x] = lvl;
    dp[x] = 1;
    for(int t:G[x]){
        if(t!=p){
            dp[x]+=dfs(t, lvl+1, x);
        }
    }
    return dp[x];
}

void init(int n){
    for(int i=0; i<=LOG; i++){
        for(int j=1; j<=n; j++){
            LCA[j][i] = -1;
        }
    }
    dfs(1,0,-1);
    for(int i=1; i<=LOG; i++){
        for(int j=1; j<=n; j++){
            if(LCA[j][i-1]!=-1){
                LCA[j][i] = LCA[LCA[j][i-1]][i-1];
            }
        }
    }
}

int getLCA(int u, int v){
    if(L[v]<L[u]){
        swap(u,v);
    }
    int d = L[v]-L[u];
    for(int i=LOG; i>=0; i--){
        if(d&(1<<i)){
            v = LCA[v][i];
        }
    }
    if(u==v){
        return v;
    }
    for(int i=LOG; i>=0; i--){
        if(LCA[u][i]!=-1 && LCA[v][i]!=LCA[u][i]){
            u = LCA[u][i];
            v = LCA[v][i];
        }
    }
    return LCA[u][0];
}

int getDist(int u, int v){
    int lca = getLCA(u,v);
    return L[u]+L[v]-2*L[lca];
}
int main(){
    int n; cin >> n;
    for(int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init(n+1);
    int q; cin >> q;
    while(q--){
        int u,v; cin >> u >> v;
        int d = getDist(u,v);
        if(d%2){
            cout << 0 << endl;
        }
        else if(u==v){
            cout << n << endl;
        }
        else if(L[u]==L[v]){
            int g = (d/2)-1;
            for(int i=LOG; i>=0; i--){
                if(g&(1<<i)){
                    u = LCA[u][i];
                    v = LCA[v][i];
                }
            }
            cout << dp[1]-dp[u]-dp[v] << endl;
        }
        else{
            if(L[v]<L[u]){
                swap(u,v);
            }
            int jump = d/2-1;
            for(int i=LOG; i>=0; i--){
                if(jump&(1<<i)){
                    v = LCA[v][i];
                }
            }
            int par_v = LCA[v][0];
            cout << dp[par_v]-dp[v] << endl;
        }
    }
}