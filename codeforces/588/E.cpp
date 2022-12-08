#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
#define nl cout << endl
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqmax;
#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)
#define N 100005
#define LOG 17

struct node{
    int par;
    set<int> pq;
    void merge(int x){
        if(pq.size()<10 || *pq.rbegin()>x){
            pq.insert(x);
        }
        if(pq.size()>10){
            pq.erase(*pq.rbegin());
        }
    }
    void merge(set<int> &p1){
        for(auto x:p1){
            if(pq.size()<10 || *pq.rbegin()>x){
                pq.insert(x);
            }
            if(pq.size()>10){
                pq.erase(*pq.rbegin());
            }
        }
    }
};
vi tr[N];
vi ppl[N];
node sparse[N][LOG];
int lvl[N];
void dfs(int x, int l, int p){
    sparse[x][0].par = p;
    for(auto t:ppl[p]){
        sparse[x][0].merge(t);
    }
    lvl[x] = l;
    for(auto u:tr[x]){
        if(u==p){
            continue;
        }
        dfs(u,l+1,x);
    }
}
int main() {
    int n,m,q; scanf("%d%d%d",&n,&m,&q);
    int u,v,x;
    fr(i,1,n,1){
        scanf("%d%d",&u,&v);
        tr[u].pb(v);
        tr[v].pb(u);
    }
    fr(i,1,m+1,1){
        scanf("%d",&x);
        if(ppl[x].size()==10){
            continue;
        }
        ppl[x].pb(i);
    }
    dfs(1,0,0);
    fr(i,1,n+1,1){
        for(int t:ppl[i]){
            sparse[i][0].merge(t);
        }
    }
    fr(j,1,LOG,1){
        fr(i,1,n+1,1){
            if(sparse[i][j-1].par==0){
                continue;
            }
            sparse[i][j].pq = sparse[i][j-1].pq;
            sparse[i][j].merge(sparse[sparse[i][j-1].par][j-1].pq);
            sparse[i][j].par = sparse[sparse[i][j-1].par][j-1].par;
        }
    }
    int aa,t;
    while(q--){
        scanf("%d %d %d",&u,&v,&aa);
        if(lvl[v]>lvl[u]){
            swap(u,v);
        }
        node a;
        for(int t:ppl[u]){
            a.merge(t);
        }
        for(int t:ppl[v]){
            a.merge(t);
        }
        int d = lvl[u]-lvl[v];
        // cout << u << " " << v << " " << d << endl;
        rfr(i,LOG-1,0,1){
            if(d&(1<<i)){
                a.merge(sparse[u][i].pq);
                u = sparse[u][i].par;
            }
        }
        if(u!=v){
            rfr(i,LOG-1,0,1){
                if(sparse[u][i].par!=0 && sparse[u][i].par!=sparse[v][i].par){
                    a.merge(sparse[u][i].pq);
                    a.merge(sparse[v][i].pq);
                    u = sparse[u][i].par, v = sparse[v][i].par;
                }
            }
            a.merge(sparse[u][0].pq);
        }
        t = min(aa,(int)a.pq.size());
        printf("%d ",t);
        while(a.pq.size()!=t){
            a.pq.erase(*a.pq.rbegin());
        }
        for(int x:a.pq){
            printf("%d ",x);
        }printf("\n");
    }
    return 0;
}