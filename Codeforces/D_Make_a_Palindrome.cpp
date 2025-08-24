#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (2 * k <= n) {
        std::cout << "YES" << std::endl;
        return;
    }

    int l = 0, r = n - 1;
    while (l < r && a[l] == a[r]) {
        l++;
        r--;
    }

    if (l >= r) {
        std::cout << "YES" << std::endl;
        return;
    }

    int p = l; 
    if (k <= p) {
        std::cout << "NO" << std::endl;
    } else {
        std::vector<int> middle;
        for (int i = l; i <= r; ++i) {
            middle.push_back(a[i]);
        }
        std::sort(middle.begin(), middle.end());

        int remaining_k = k - p;
        int removable_count = 0;
        for (size_t i = 0; i < middle.size(); ++i) {
            if (i + 1 <= remaining_k) {
                removable_count++;
            } else if (middle[i] == middle[i - remaining_k]) {
                removable_count++;
            }
        }
        
        if (removable_count >= (r - l + 1)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}