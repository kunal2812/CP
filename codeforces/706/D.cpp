#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fr(i, a, b, c) for(int i=a; i<b; i+=c)
#define rfr(i, a, b, c) for(int i=a; i>=b;i-=c)

struct Node{
    Node* links[2];
    int cnt[2];
    bool containsKey(int x){
        return links[x]!=NULL;
    }
    void setKey(int x, Node* node){
        links[x] = node;
    }
    Node* getKey(int x){
        return links[x];
    }
    void incrementCnt(int x){
        cnt[x]++;
    }
    void decrementCnt(int x){
        cnt[x]--;        
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int x){
        Node* node = root;
        rfr(i,30,0,1){
            if(x&(1<<i)){
                if(!node->containsKey(1)){
                    node->setKey(1,new Node());
                }
                node->incrementCnt(1);
                node = node->getKey(1);
            }
            else{
                if(!node->containsKey(0)){
                    node->setKey(0,new Node());
                }
                node->incrementCnt(0);
                node = node->getKey(0);
            }
        }
    }
    void erase(int x){
        Node* node = root;
        rfr(i,30,0,1){
            if(x&(1<<i)){
                node->decrementCnt(1);
                node = node->getKey(1);
            }
            else{
                node->decrementCnt(0);
                node = node->getKey(0);
            }
        }
    }
    int getMax(int x){
        Node* node = root;
        int ans = 0;
        rfr(i,30,0,1){
            if(x&(1<<i)){
                if(node->containsKey(0) && node->cnt[0]){
                    ans|=(1<<i);
                    node = node->getKey(0);
                }
                else{
                    node = node->getKey(1);
                }
            }
            else{
                if(node->containsKey(1) && node->cnt[1]){
                    ans|=(1<<i);
                    node = node->getKey(1);
                }
                else{
                    node = node->getKey(0);
                }
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    Trie* t = new Trie();
    t->insert(0);
    while(q--){
        string s; int x; cin >> s >> x;
        if(s=="+"){
            t->insert(x);
        }
        else if(s=="-"){
            t->erase(x);
        }
        else{
            cout << t->getMax(x) << endl;
        }
    }
    return 0;
}
