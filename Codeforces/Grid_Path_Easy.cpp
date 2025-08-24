#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N, Q;
        cin >> N >> Q;
        string s1, s2;
        cin >> s1 >> s2;
        // collect positions of '1's in each row (1-based indexing)
        vector<int> P, Qpos;
        for(int i = 0; i < N; i++){
            if(s1[i]=='1') P.push_back(i+1);
            if(s2[i]=='1') Qpos.push_back(i+1);
        }
        int Y1 = P.size(), Y2 = Qpos.size();

        // cost1[k] = min swaps to bring first k ones to positions 1..k
        //   = sum_{j=1..k} |P[j] - j|
        vector<ll> cost1(Y1+1, 0);
        for(int k = 1; k <= Y1; k++){
            cost1[k] = cost1[k-1] + ll(abs(P[k-1] - k));
        }

        // cost2[t] = min swaps to bring last t ones to positions (N-t+1)..N
        //   match Qpos[Y2-t .. Y2-1] → slots (N-t+1)+j-1
        vector<ll> cost2(Y2+1, 0);
        for(int t = 1; t <= Y2; t++){
            int one_idx = Y2 - t;           // which one in Qpos
            int target_pos = (N - t + 1);   // slot start
            // match this one to slot target_pos + (j-1)
            cost2[t] = cost2[t-1]
                     + ll(abs(Qpos[one_idx] - (target_pos + (t-1))));
        }

        const ll INF = (ll)4e18;
        ll ans = INF;
        // try the single down‑move at column k (1 ≤ k ≤ N):
        //   row1 needs ones at cols 1..k   → need k ≤ Y1
        //   row2 needs ones at cols k..N   → need (N-k+1) ≤ Y2
        for(int k = 1; k <= N; k++){
            int t = N - k + 1;
            if(k <= Y1 && t <= Y2){
                ans = min(ans, cost1[k] + cost2[t]);
            }
        }

        cout << (ans==INF ? -1 : ans) << "\n";

        // skip any updates (Q==0 in this version)
        for(int i=0;i<Q;i++){
            int x,y; 
            cin>>x>>y;
        }
    }
    return 0;
}
