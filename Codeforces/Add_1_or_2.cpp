#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<ll> A(N), B(N);
        ll sumB = 0;
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        for(int i = 0; i < N; i++){
            cin >> B[i];
            sumB += B[i];
        }

        ll lo = *max_element(A.begin(), A.end());
        ll hi = lo + sumB; 

        auto feasible = [&](ll M){
            ll usedSelf = 0;
            vector<ll> cap(N);
            for(int i = 0; i < N; i++){
                ll can = M > A[i] ? M - A[i] : 0;
                cap[i] = min(B[i], can);
                usedSelf += cap[i];
            }
            ll rem = sumB - usedSelf;
            if(rem <= 0) return true;

            ll slots = 0;
            for(int i = 0; i < N; i++){
                ll curr = A[i] + cap[i];
                if(curr < M){
                    slots += (M - curr) / 2;
                    if(slots >= rem) return true;
                }
            }
            return slots >= rem;
        };

        while(lo < hi){
            ll mid = lo + (hi - lo) / 2;
            if(feasible(mid)) hi = mid;
            else lo = mid + 1;
        }

        cout << lo << "\n";
    }

    return 0;
}
