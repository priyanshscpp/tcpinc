#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        bool ok = (x==0)          // no 0’s ⇒ only 1’s & 2’s ⇒ all adj sums ≥2
               || (y>0 ? z>=x     // if any 1’s, need ≥x twos (to separate each 0 and the 1-block)
                       : z>=x-1)  // no 1’s, just need ≥x‑1 twos (to separate all zeros)
        ;
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
