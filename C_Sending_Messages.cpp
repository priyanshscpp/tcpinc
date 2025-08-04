#include<iostream>
using namespace std;
int main(){
	long long n,f,a,b,t;
	cin>>t;
	while(t--){
		long long l=0,r=0,sum = 0;
		cin>>n>>f>>a>>b;
		for(int i = 1; i <= n; i++){
			cin>>r;
			sum += min((r-l)*a,b);
			l = r;
		}
		if(sum >= f){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
}
			   		    	 	 	  	  		  		 		