#include<bits/stdc++.h>
using  namespace std;

#define ll long long 
const int maxn=16;

int main(){


    int n;
    cin>>n;
    int tot=1 <<n;
    for(int i=0; i<tot; i++){
        int gray = i^(i>>1);
        bitset<maxn> bits(gray);
        string grys=bits.to_string();

        cout<<grys.substr(maxn-n)<<endl;
    }


    return 0;

}