#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int maxn=1e6;
const int MOD =1e9+7;

int n ,dp[maxn+1];
int main (){

    cin>>n;
    dp[0]=1;
    for(int i=0; i<=n; i++){
        for(int j=1; j<=6 && i-j>=0; j++ ){
            dp[i]=(dp[i]+dp[i-j])% MOD;

        }
    }
    cout<<dp[n]<<endl;


    return 0;

}