#include <bits/stdc++.h>
using namespace std;



void move(int from, int to ,int n){
    if(n==1){
        cout<<from<<" "<<to<<endl;
        return ;
    }
    int aux = 6-from-to;
    move(from, aux,n-1);
    cout<<from<<" "<<to<<endl;
    move(aux,to,n-1);


}
int main(){


    int n;
    cin>>n;
    int total =(1<<n)-1;
    cout<<total<<endl;
    move(1,3,n);


    return 0;

}