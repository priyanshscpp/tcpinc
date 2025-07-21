#include <bits/stdc++.h>

using namespace std;

const int maxx=1e6;
const int INF=0x3f3f3f3f;

int N,x,c ,dp[maxx+1];

int main (){
   cin>>N>>x;
   fill(dp+1, dp+x+1,INF);
   for(int i=0; i<N; i++){
    cin>>c;
    for(int j=0; j<=x-c; j++)
    if(dp[j]!=INF)
      dp[j+c]=min(dp[j+c],dp[j]+1);

   }
   cout<<(dp[x]==INF ?-1:dp[x])<<endl;


    return 0;

}