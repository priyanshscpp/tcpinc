#include <bits/stdc++.h>
using namespace std;

const int n=8;
vector<string> board(n);
int ans=0;

bool col[n]={},diag1[2*n]={},diag2[2*n]={};

void dfs(int row){
    if(row==n){
        ++ans;
        return ;
    }
    for(int coli=0; coli<n; ++coli){
        if(board[row][coli]=='*')continue;
        if(col[coli]||diag1[row -coli+n]|| diag2[row + coli])continue;

        col[coli] = diag1[row -coli + n] = diag2[row+coli] = true;
        dfs(row+1);
        col[coli] = diag1[row-coli +n] = diag2[row+coli] = false;
    }
}
int main(){


    for(int i=0; i<n; i++){
        cin>>board[i];

    }
    dfs(0);
    cout<<ans<<endl;

    
    return 0;

}
