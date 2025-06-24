#include <bits/stdc++.h>
using namespace std;

int main(){

string s;
cin>>s;
set<string> perm;
sort(s.begin(),s.end());

do{
    perm.insert(s);

}while(next_permutation(s.begin(),s.end()));

cout<<perm.size()<<endl;
for(const auto a:perm){
    cout<<a<<endl;

}
    return 0;
}