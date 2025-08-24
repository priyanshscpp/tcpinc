#include <bits/stdc++.h>
using namespace std;
      
/* OM NAMO NARAYANA */
/* Code written by Priyanshu Yadav  */
/* OS : Arch Linux (Rolling Release) */

/* TYPES  */
#define int long long

/* clang-format on */


/* Main()  function */
int n,x;
main()
{
	for(cin>>n;cin>>x>>n;)
	{
		for(int i=n/4*4+1;i<=n;i++)
			x+=(x&1?i:-i);
		cout<<x<<'\n';
	}
}
