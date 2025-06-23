#include <bits/stdc++.h>
using namespace std;
using L=int64_t;
int main()
{
    L t;
    cin>>t;
    while(t--){
    L n;
    cin>>n;
    map<tuple<L,L,L>,L> C;
    L a,b,c,A=0;
    cin>>b>>c;
    n-=2;
    while(n--){
    a=b;
    b=c;
    cin>>c;
    A+=++C[{0,b,c}]+ ++C[{a,0,c}]+ ++C[{a,b,0}]-++C[{a,b,c}]*3;
    }
    cout<<A<<' ';
    }
    return 0;
}