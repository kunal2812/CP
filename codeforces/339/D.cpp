#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define N 1<<17 + 5

int a[N];
int seg[4*N];

void build(int si, int ss, int se, int lvl, int t){
    if(ss==se){
        seg[si] = a[ss];
        return;
    }
    int mid = (ss+se)>>1;
    build(2*si,ss,mid,lvl+1,t);
    build(2*si+1,mid+1,se,lvl+1,t);
    if(t%2){
        if(lvl%2)
            seg[si] = seg[2*si]|seg[2*si+1];
        else
            seg[si] = seg[2*si]^seg[2*si+1];
    }
    else{
        if(lvl%2)
            seg[si] = seg[2*si]^seg[2*si+1];
        else
            seg[si] = seg[2*si]|seg[2*si+1];
    }
}
void update(int si, int ss, int se, int qi, int val, int lvl, int t){
    if(ss==se){
        seg[si] = val;
        return;
    }
    int mid = (ss+se)>>1;
    if(qi<=mid) update(2*si,ss,mid,qi,val,lvl+1,t);
    else update(2*si+1,mid+1,se,qi,val,lvl+1,t);
    if(t%2){
        if(lvl%2)
            seg[si] = seg[2*si]|seg[2*si+1];
        else
            seg[si] = seg[2*si]^seg[2*si+1];
    }
    else{
        if(lvl%2)
            seg[si] = seg[2*si]^seg[2*si+1];
        else
            seg[si] = seg[2*si]|seg[2*si+1];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t,m; cin >> t >> m;
    int n = 1<<t;
    for(int i=1; i<=n; i++) cin >> a[i];
    build(1,1,n,1,t);
    int p,b;
    while(m--){
        cin >> p >> b;
        update(1,1,n,p,b,1,t);
        a[p] = b;
        // for(int i=1; i<=4*n; i++){
        //     cout << seg[i] << " ";
        // }cout << endl;
        cout << seg[1] << endl;
    }
    return 0;
}
