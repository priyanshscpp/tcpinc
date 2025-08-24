#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<vector<int>> p(k+2);
        for(int i=0;i<n;i++){
            p[a[i]].push_back(i);
        }
        vector<ll> dpn;
        int m = p[k].size();
        dpn.assign(m,0);
        for(int i=k-1;i>=1;i--){
            auto &cur=p[i];
            auto &nxt=p[i+1];
            int m0=cur.size(), m1=nxt.size();
            vector<ll> v1(m1), v2(m1), pref(m1), suff(m1), dpc(m0);
            for(int j=0;j<m1;j++){
                v1[j]=dpn[j] - nxt[j];
                v2[j]=dpn[j] + nxt[j];
            }
            pref[0]=v1[0];
            for(int j=1;j<m1;j++) pref[j]=min(pref[j-1], v1[j]);
            suff[m1-1]=v2[m1-1];
            for(int j=m1-2;j>=0;j--) suff[j]=min(suff[j+1], v2[j]);
            for(int j=0;j<m0;j++){
                int x=cur[j];
                ll best=LLONG_MAX;
                int idx=upper_bound(nxt.begin(), nxt.end(), x) - nxt.begin() - 1;
                if(idx>=0) best = min(best, pref[idx] + x);
                int idx2 = lower_bound(nxt.begin(), nxt.end(), x) - nxt.begin();
                if(idx2 < m1) best = min(best, suff[idx2] - x);
                dpc[j]=best;
            }
            dpn.swap(dpc);
        }
        auto &V = p[1];
        int m1 = V.size();
        vector<ll> v1(m1), v2(m1), pref(m1), suff(m1);
        for(int j=0;j<m1;j++){
            v1[j]=dpn[j] - V[j];
            v2[j]=dpn[j] + V[j];
        }
        pref[0]=v1[0];
        for(int j=1;j<m1;j++) pref[j]=min(pref[j-1], v1[j]);
        suff[m1-1]=v2[m1-1];
        for(int j=m1-2;j>=0;j--) suff[j]=min(suff[j+1], v2[j]);
        vector<ll> ans(n);
        for(int s=0;s<n;s++){
            ll best=LLONG_MAX;
            int idx=upper_bound(V.begin(), V.end(), s) - V.begin() - 1;
            if(idx>=0) best = min(best, pref[idx] + s);
            int idx2 = lower_bound(V.begin(), V.end(), s) - V.begin();
            if(idx2 < m1) best = min(best, suff[idx2] - s);
            ans[s]=best;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<(i+1<n?' ':'\n');
        }
    }
    return 0;
}
