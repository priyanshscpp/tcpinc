#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n, m, L;
        cin >> n >> m >> L;
        vector<int> A(L);
        ll total = 0;
        int max_even = -1, max_odd = -1;
        for(int i = 0; i < L; i++){
            cin >> A[i];
            total += A[i];
            if ((A[i] & 1) == 0) max_even = max(max_even, A[i]);
            else               max_odd  = max(max_odd,  A[i]);
        }

        vector<vector<int>> adj(n+1);
        for(int i = 0, u, v; i < m; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS from 1: compute dist[], detect bipartiteness
        vector<int> dist(n+1, -1), color(n+1, -1);
        queue<int> q;
        dist[1] = 0;
        color[1] = 0;
        q.push(1);
        bool is_bip = true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else {
                    // if already seen, check for conflict
                    if((color[v] ^ color[u]) != 1){
                        is_bip = false;
                    }
                }
            }
        }

        vector<char> ans(n+1,'0');
        // vertex 1 is always reachable
        ans[1] = '1';

        if(!is_bip){
            // parity is irrelevant: any walk-length ≤ total
            for(int v = 2; v <= n; v++){
                if(dist[v] != -1 && dist[v] <= total)
                    ans[v] = '1';
            }
        } else {
            int total_parity = total & 1;
            for(int v = 2; v <= n; v++){
                if(dist[v] < 0) continue;
                int d = dist[v];
                // try largest even segment
                if(max_even >= 0 && (d % 2) == 0 && d <= max_even){
                    ans[v] = '1';
                    continue;
                }
                // try largest odd segment
                if(max_odd >= 0 && (d % 2) == 1 && d <= max_odd){
                    ans[v] = '1';
                    continue;
                }
                // try the total-sum segment
                if((d % 2) == total_parity && d <= total){
                    ans[v] = '1';
                }
            }
        }

        // output the binary string of length n
        for(int i = 1; i <= n; i++) cout << ans[i];
        cout << "\n";
    }
    return 0;
}
