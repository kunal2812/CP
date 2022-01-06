#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ff first
#define sc second
#define endl '\n'
#define nl cout << endl

typedef vector<int> vi;
typedef pair<int, int> pii;

#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

int cnt = 0;
unordered_map<int,int> tab;
map<int,int> parent;

int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x] = find(parent[x]);
}
void merge(int x, int y){
    if(tab.find(x)==tab.end() || x==y){
        return;
    }
    if(tab.find(y)==tab.end()){
        int p = tab[x];
        tab[y] = p;
        tab.erase(x);
        return;
    }
    int q = x;
    x = find(tab[x]);
    y = find(tab[y]);
    if(x!=y){
        parent[x] = y; 
    }
    tab.erase(q);
}
void make(int x){
    if(tab.find(x)==tab.end()){
        parent[cnt] = cnt;
        tab[x] = cnt;
        cnt++;
    }
    else{
        parent[cnt] = tab[x];
        cnt++;
    }
}
void print(){
    unordered_map<int, int> m;
    // cout << "PARENT" << endl;
    for(auto t:parent){
        int x = t.ff, y = t.sc;
        parent[x] = find(y);
    //     // cout << x.ff << " " << x.sc << endl;
    }
    // cout << "TAB" << endl;
    for(auto x:tab){
        // cout << x.ff << " " << x.sc << endl;
        m[x.sc] = x.ff;
    }
    // nl;
    // cout << "ARRAY" << endl;
    for(pii x:parent){
        cout << m[x.sc] << " ";
    }nl;
}

void Solution(){ 
    int q; cin >> q;
    int x,a,b;
    while(q--){
        cin >> x; 
        if(x==1){
            cin >> a;
            make(a);
        }
        else{
            cin >> a >> b;
            merge(a,b);
            
        }
        // print();
    }
    print();
}

int main() {
    fast;
    Solution();
    return 0;
}
