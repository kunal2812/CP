#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define N 1000002
struct node{
    int x=0,y=0,z=0;
};
string a;
node seg[4*N];

void build(int si, int ss, int se){
    if(ss==se){
        if(a[ss]=='('){
            seg[si].y++;
        }
        else{
            seg[si].z++;
        }
        return;
    }
    int mid = (ss+se)>>1;
    build(2*si, ss,mid);
    build(2*si+1,mid+1,se);
    int t = min(seg[2*si].y, seg[2*si+1].z);
    seg[si].y+=(seg[2*si].y+seg[2*si+1].y-t);
    seg[si].z+=(seg[2*si].z+seg[2*si+1].z-t);
    seg[si].x+=(seg[2*si].x+seg[2*si+1].x+t);
}

node query(int si, int ss, int se, int qs, int qe){
    if(qs>se || ss>qe){
        return {0,0,0};
    }
    if(ss>=qs && se<=qe){
        return seg[si];
    }
    int mid = (ss+se)>>1;
    node L = query(2*si,ss,mid,qs,qe);
    node R = query(2*si+1,mid+1,se,qs,qe);
    int p=0,q=0,r=0;
    int t = min(L.y, R.z);
    q+=(L.y+R.y-t);
    r+=(L.z+R.z-t);
    p+=(L.x+R.x+t);
    return {p,q,r};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a;
    a = '#'+a;
    int n = a.size()-1;
    build(1,1,n);
    int q; cin >> q;
    int l,r; 
    while(q--){
        cin >> l >> r;
        cout << 2*query(1,1,n,l,r).x << endl;
    }
    return 0;
}
