#include<bits/stdc++.h>
using namespace std;

int main(){


    string s;
    cin>>s;

    map<char,int> freq;
    for(char c:s)freq[c]++;
    
    int oddcnt=0;
    char oddchar='\0';
    for(auto &[ch,cnt]: freq)
    if(cnt %2 !=0){
        oddcnt++;
        oddchar=ch;

    }

    string mid,half;

    if(oddcnt>1){cout<<"NO SOLUTION"; return 0;}
    for(auto &[ch,cnt]:freq){
        half +=string(cnt/2,ch);

    }

    if(oddcnt==1)
      mid =string(freq[oddchar] % 2 == 1 ? freq[oddchar] - 2 * (freq[oddchar] / 2) : 0, oddchar);
    string result = half +mid;
    reverse(half.begin(), half.end());
    result +=half;

    cout<<result<<endl;

   

}