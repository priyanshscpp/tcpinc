#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){

    ll t;
    cin>>t;
    while (t--)
    {
     ll n,a,b;
     cin>>n>>a>>b;
     if(a+b>n || (a==0)^(b==0)){
        cout<<"NO"<<endl;
        continue;
     }
     cout<<"YES"<<endl;
     vector<ll> p(n);
     iota(p.begin(),p.end(),1);
     for(auto x:p)cout<<x<<" ";
     cout<<endl;
     ll t= n-(a+b);
     vector<ll> q=p;
     
     rotate(q.begin()+t,q.begin()+t+a,q.end());
     for(auto x:q)cout<<x<<" ";
     cout<<endl;
    }
    
    
    return 0;

}