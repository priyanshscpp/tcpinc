#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int parent[MAXN], sizeGroup[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sizeGroup[a] < sizeGroup[b])
            swap(a, b);
        parent[b] = a;
        sizeGroup[a] += sizeGroup[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sizeGroup[i] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        vector<int> group(k);
        for (int j = 0; j < k; ++j)
            cin >> group[j];

        for (int j = 1; j < k; ++j)
            unite(group[0], group[j]);
    }

    for (int i = 1; i <= n; ++i)
        cout << sizeGroup[find(i)] << " ";
    cout << "\n";

    return 0;
}
