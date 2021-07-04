#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define endl '\n'
#define nl cout << endl;


char mat[502][502];
bool check[502][502];
int star[502][502];
void Solution(){ 
    int n,m;
    cin >> n >> m;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='*'){
                star[i][j] = star[i][j-1]+1;
            }
            else{
                star[i][j] = star[i][j-1];
            }
            check[i][j] = false;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check[i][j]){
                continue;
            }
            int h=0;
            if(mat[i][j]=='*'){
                check[i][j] = true;
                ans++;
                h++;
                for(int k = h+i;k<=n;k++){
                    if((j-h)<1 || (j+h)>m){
                        goto label;
                    }
                    if((star[i+h][j+h]-star[i+h][j-h-1])==((2*(h+1))-1)){
                        ans++;
                        h++;
                    }
                    else{
                        break;
                    }
                }
            }
            label:;
        }
    }
    cout << ans << endl;
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

