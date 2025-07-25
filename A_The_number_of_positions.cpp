#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, a, b;
    cin >> n >> a >> b;
    cout << min(n - a, b + 1) << '\n';
    return 0;
}