#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, S;
    cin >> K >> S;

    long long count = 0;
    for (int x = 0; x <= K; ++x) {
        // Compute Y-range so that Z = S - x - y is in [0, K]
        int lowY  = max(0, S - x - K);
        int highY = min(K, S - x);
        if (lowY <= highY) {
            count += (highY - lowY + 1);
        }
    }

    cout << count << "\n";
    return 0;
}
