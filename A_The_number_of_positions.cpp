#include <iostream>
using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    cout << min(n - a, b + 1) << '\n';
    return 0;
}