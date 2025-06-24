#include <bits/stdc++.h>
using namespace std;

#define ll long long 
int main(){

ll n;
cin>>n;
vector<ll> v(n);
for(ll i=0; i<n; i++){
    cin>>v[i];
}
ll best =LLONG_MAX;
for(int m=0; m<(1<<n); m++){
    ll a=0, b=0;
    for(int j=0; j<(n); j++){
        if(m & (1 << j))  a += v[j];
        else b+=v[j];
    }
    best =min(best,abs(a-b));

}
cout<<best<<endl;


    return 0;

}