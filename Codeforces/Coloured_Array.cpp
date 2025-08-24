#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF_LL = (ll)4e18;

struct HopcroftKarp {
    int n, m; // n = left size, m = right size
    vector<vector<int>> adj;
    vector<int> dist, pairU, pairV;

    HopcroftKarp(int _n, int _m): n(_n), m(_m) {
        adj.assign(n, {});
        pairU.assign(n, -1);
        pairV.assign(m, -1);
        dist.assign(n, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int>q;
        for(int u = 0; u < n; u++){
            if(pairU[u] < 0){ dist[u] = 0; q.push(u); }
            else dist[u] = -1;
        }
        bool found = false;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: adj[u]){
                int pu = pairV[v];
                if(pu < 0) found = true;
                else if(pu >= 0 && dist[pu] < 0){
                    dist[pu] = dist[u] + 1;
                    q.push(pu);
                }
            }
        }
        return found;
    }

    bool dfs(int u){
        for(int v: adj[u]){
            int pu = pairV[v];
            if(pu < 0 || (pu >= 0 && dist[pu] == dist[u] + 1 && dfs(pu))){
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int maxMatching(){
        int result = 0;
        while(bfs()){
            for(int u = 0; u < n; u++){
                if(pairU[u] < 0 && dfs(u)) result++;
            }
        }
        return result;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> A(2*N);
        for(int i = 0; i < 2*N; i++) cin >> A[i];

        vector<vector<int>> dbl(N+1);
        vector<array<int,3>> singles;
        for(int i = 0; i < N; i++){
            int x = A[2*i], y = A[2*i+1];
            if(x == y) dbl[x].push_back(i);
            else singles.push_back({i, x, y});
        }

        vector<char> usedVal(N+1, 0), usedBlock(N, 0);
        ll totalMatch = 0;
        for(int v = 1; v <= N; v++){
            if(!dbl[v].empty()){
                int b = dbl[v].back();
                usedVal[v] = 1;
                usedBlock[b] = 1;
                totalMatch += 2;
            }
        }

        vector<int> freeBlocks;
        for(auto &s: singles) freeBlocks.push_back(s[0]);
        for(int v = 1; v <= N; v++){
            for(int b: dbl[v]) if(!usedBlock[b]) freeBlocks.push_back(b);
        }

        int M = freeBlocks.size();
        HopcroftKarp hk(M, N+1); // right nodes 1..N
        for(auto &s: singles){
            int b = s[0], x = s[1], y = s[2];
            int u = int(find(freeBlocks.begin(), freeBlocks.end(), b) - freeBlocks.begin());
            if(!usedVal[x]) hk.addEdge(u, x);
            if(!usedVal[y]) hk.addEdge(u, y);
        }
        for(int v = 1; v <= N; v++){
            if(usedVal[v]) continue;
            for(int b: dbl[v]) if(!usedBlock[b]){
                int u = int(find(freeBlocks.begin(), freeBlocks.end(), b) - freeBlocks.begin());
                hk.addEdge(u, v);
            }
        }

        totalMatch += hk.maxMatching();
        cout << (2LL*N - totalMatch) << '\n';
    }
    return 0;
}
