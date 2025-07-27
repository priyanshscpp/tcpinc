#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn =100;
const int maxx =1e6;
const ll MOD=1e9+7;

int main(){

    ll n,x,c;
    cin>>n>>x;

    vector<ll> dp(maxx+1);

    for(int i=0; i<n; i++){
       cin>>c;
       
       dp[0]=1; // Base case;
      for(int j=0; j<=x-c; j++)
        dp[j+c]= (dp[j+c]+ dp[j]) % MOD ;
    }
    cout<<dp[x]<<endl;

    return 0;
}