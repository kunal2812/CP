#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define endl '\n'
#define nl cout << endl;

void Solution(){ 
    string ss;
    cin >> ss;
    stack<char> s;
    int n = ss.length();
    for(int i=0;i<n;i++){
        if(ss[i]=='A'){
            s.push('A');
        }
        else if(s.size()>0){
            s.pop();
        }
        else{
            s.push(ss[i]);
        }
    }
    cout << s.size() << endl;
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

