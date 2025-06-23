#include <bits/stdc++.h>
using namespace std;
int n, m, z = 1, k;
int main()
{
    cin >> n >> m;
    if (n > m + 1 || n * 2 + 2 < m)
        return cout << -1, 0;
    while (n || m)
    {
        if ((m > n && k < 2) || z == 0)
            m--, z = 1, k++;
        else
            n--, z = 0, k = 0;
        cout << z;
    }
}