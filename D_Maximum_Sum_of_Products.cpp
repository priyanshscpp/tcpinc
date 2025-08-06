#include <bits/stdc++.h>
using namespace std;
      
/* OM NAMO NARAYANA */
/* Code written by Priyanshu Yadav  */
/* Operating System : Ubuntu LTS 24.04  */

/* TYPES  */
#define int long long 


/* clang-format on */
int a[5009];
int b[5009];
int dp[5009][5009];
int dpp(int i, int j ){
    if(i>j)return 0;
    if(i==j)return a[i]*b[j];
    if(dp[i][j] !=-1) return dp[i][j];
    return dp[i][j]=dpp(i+1,j-1)+a[i]*b[j]+a[j]*b[i];

}


/* Main()  function */
signed  main()
{
int n;cin>>n;
memset(dp,-1,sizeof(dp));
for(int i=1;i<=n; i++)cin>>a[i];
for(int i=1; i<=n; i++)cin>>b[i];
int ans=0, to=0;
for(int i=1; i<=n; i++){
    to +=(a[i]*b[i]);

}
ans=to;
for(int i=1; i<=n; i++){
    int z=0; 
    for(int j=i; j<=n; j++){
        z +=(a[j]*b[j]);
        ans=max(ans,to -z+dpp(i,j));

    }

}
cout<<ans<<endl;


    return 0;
}


