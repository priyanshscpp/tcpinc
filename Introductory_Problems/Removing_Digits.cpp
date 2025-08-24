#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn=1e6;
const int INF=0x3f3f3f3f;

int dp[maxn+1];

int main(){
ll n;
cin>>n;

fill(dp+1,dp+n+1,INF);

for(int i=1; i<=n; i++){
    int d=i;
    while(d>0){
        if(d%10 !=0)
         dp[i]= min(dp[i],dp[i-(d%10)]+1);
       d /= 10;

    }
}

cout<<dp[n]<<endl;

    return 0;

}