#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cntSum(const vector<ll>& a, int L, int R, ll S) {
    unordered_map<ll,int> mp;
    mp.reserve(R - L + 3);
    mp[0] = 1;
    ll cur = 0, res = 0;
    for (int i = L; i <= R; i++) {
        cur += a[i];
        auto it = mp.find(cur - S);
        if (it != mp.end()) res += it->second;
        mp[cur]++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; 
    cin >> T;
    while (T--) {
        int n; ll S, X;
        cin >> n >> S >> X;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll ans = 0;
        int i = 0;
        while (i < n) {
            if (a[i] > X) { i++; continue; }
            int j = i;
            while (j < n && a[j] <= X) j++;
            // block [i..j-1]
            ll total = cntSum(a, i, j-1, S);
            ll sub = 0;
            int last = i;
            for (int k = i; k < j; k++) {
                if (a[k] == X) {
                    if (last <= k-1)
                        sub += cntSum(a, last, k-1, S);
                    last = k+1;
                }
            }
            if (last <= j-1)
                sub += cntSum(a, last, j-1, S);
            ans += total - sub;
            i = j;
        }
        cout << ans << '\n';
    }
    return 0;
}
