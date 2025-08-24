#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll,ll> count_subseq(const string &s) {
    ll z = 0, o = 0;
    ll c01 = 0, c10 = 0;
    ll c010 = 0, c101 = 0;
    ll c0101 = 0, c1010 = 0;
    for(char ch: s) {
        if(ch == '0') {
            c10 += o;
            c1010 += c101;
            z++;
            c010 += c01;
        } else {
            c01 += z;
            c0101 += c010;
            o++;
            c101 += c10;
        }
    }
    return {c0101, c1010};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int N;
        ll A, B, C, D;
        cin >> N >> A >> B >> C >> D;

        ll answer = 0;
        for(int z = 0; z <= N; z++){
            int o = N - z;
            ll base = A * (ll)z * (z - 1) / 2 + B * (ll)o * (o - 1) / 2;
            ll best_reward = 0;

            vector<string> candidates;
            candidates.reserve(6);

            {
                string s;
                s.append(z, '0');
                s.append(o, '1');
                candidates.push_back(move(s));
            }
            {
                string s;
                s.append(o, '1');
                s.append(z, '0');
                candidates.push_back(move(s));
            }
            {
                string s;
                int rz = z, ro = o;
                int k = min(rz, ro);
                for(int i = 0; i < k; i++){
                    s.push_back('0');
                    s.push_back('1');
                }
                rz -= k;
                ro -= k;
                if(rz > 0) s.append(rz, '0');
                else if(ro > 0) s.append(ro, '1');
                candidates.push_back(move(s));
            }
            {
                string s;
                int rz = z, ro = o;
                int k = min(rz, ro);
                for(int i = 0; i < k; i++){
                    s.push_back('1');
                    s.push_back('0');
                }
                rz -= k;
                ro -= k;
                if(ro > 0) s.append(ro, '1');
                else if(rz > 0) s.append(rz, '0');
                candidates.push_back(move(s));
            }
            {
                string s;
                int rz = z, ro = o;
                if(rz > ro) {
                    int extra = rz - ro;
                    s.append(extra, '0');
                    rz -= extra;
                } else if(ro > rz) {
                    int extra = ro - rz;
                    s.append(extra, '1');
                    ro -= extra;
                }
                int k = min(rz, ro);
                for(int i = 0; i < k; i++){
                    s.push_back('0');
                    s.push_back('1');
                }
                candidates.push_back(move(s));
            }
            {
                string s;
                int rz = z, ro = o;
                if(ro > rz) {
                    int extra = ro - rz;
                    s.append(extra, '1');
                    ro -= extra;
                } else if(rz > ro) {
                    int extra = rz - ro;
                    s.append(extra, '0');
                    rz -= extra;
                }
                int k = min(rz, ro);
                for(int i = 0; i < k; i++){
                    s.push_back('1');
                    s.push_back('0');
                }
                candidates.push_back(move(s));
            }

            for(auto &s : candidates){
                if((int)s.size() != N) continue;
                auto pr = count_subseq(s);
                ll reward = C * pr.first + D * pr.second;
                best_reward = max(best_reward, reward);
            }

            answer = max(answer, base + best_reward);
        }

        cout << answer << "\n";
    }
    return 0;
}
