#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int maxn=100;
const int maxx=1e6;
const ll MOD =1e9+7;

int main(){

    ll n,x;
    cin>>n>>x;
    vector<ll> c(maxn);

    vector<ll> dp(maxx);
    for(int i=0; i<n; i++){
        cin>>c[i];

    }
    dp[0]=1; //Base case
    for(int i=0; i<x; i++)
     if(dp[i]!= 0)
       for(int j=0; j<n; j++)
         if(i+c[j]<=x)
           dp[i+c[j]]=(dp[i+c[j]]+ dp[i])% MOD;



    cout<<dp[x]<<endl;//printf the code 


    return 0;

}