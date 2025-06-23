#include <bits/stdc++.h>
using namespace std;

/* OM NAMO NARAYANA */
/* Code written by Priyanshu Yadav  */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a, int b) { if (a < b) return a; return b; }
ll min(int a, ll b) { if (a < b) return a; return b; }
ll max(ll a, int b) { if (a > b) return a; return b; }
ll max(int a, ll b) { if (a > b) return a; return b; }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }
bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return 0; return 1; }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

/* clang-format on */


void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int,int>> ops;
    ops.reserve(4 * n * n);

    auto do_swap = [&](int type, int i) {
        ops.emplace_back(type, i + 1);
        if (type == 1) swap(a[i], a[i+1]);
        else if (type == 2) swap(b[i], b[i+1]);
        else swap(a[i], b[i]);
    };

    for (int i = 0; i < n; i++) {
        int targetA = i + 1;
        int foundR = -1, idx = -1;
        for (int r = 0; r < 2; r++) {
            auto &arr = (r == 0 ? a : b);
            auto it = find(arr.begin() + i, arr.end(), targetA);
            if (it != arr.end()) {
                foundR = r;
                idx = it - arr.begin();
                break;
            }
        }
        if (foundR == 1) {
            while (idx > i) {
                do_swap(2, idx - 1);
                idx--;
            }
            do_swap(3, i);
        } else {
            while (idx > i) {
                do_swap(1, idx - 1);
                idx--;
            }
        }

        int targetB = n + i + 1;
        foundR = -1; idx = -1;
        for (int r = 0; r < 2; r++) {
            auto &arr = (r == 0 ? a : b);
            auto it = find(arr.begin() + i, arr.end(), targetB);
            if (it != arr.end()) {
                foundR = r;
                idx = it - arr.begin();
                break;
            }
        }
        if (foundR == 0) {
            while (idx > i) {
                do_swap(1, idx - 1);
                idx--;
            }
            do_swap(3, i);
        } else {
            while (idx > i) {
                do_swap(2, idx - 1);
                idx--;
            }
        }
    }

    cout << ops.size() << "\n";
    for (auto &p : ops) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
