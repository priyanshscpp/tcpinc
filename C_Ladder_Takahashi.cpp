#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
   int n;
   cin>>n;
   map<int, vector<int> >graph ;
   for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
     graph[a].push_back(b);
     graph[b].push_back(a);
}

//entry done ..
//traversal start ...
queue<int> que;
que.push(1);


set<int>s;
s.insert(1); //all visited floors;

while(!que.empty()){
    int v=que.front(); que.pop();
    for(int i: graph[v]){
        if(!s.count(i)){
            que.push(i);
            s.insert(i);

        }
    }
}

cout<<*s.rbegin()<<endl;

}
