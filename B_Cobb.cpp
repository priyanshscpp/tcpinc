#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],K;
void Solve(){
	cin>>n>>K;
	ll mx=-1e18;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1&&i>=n-200;i--){
		for(int j=i-1;j>=1;j--){
			mx=max(mx,1ll*i*j-1ll*K*(a[i]|a[j]));
		}
	}
	cout<<mx<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
    return 0;
}