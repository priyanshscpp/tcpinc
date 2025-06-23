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
 
inline int pc(ll x) {                
    return __builtin_popcountll(x);
}

void namo() {
    int n;  ll k;                     cin >> n >> k;
    vector<ll> a(n);                  for (ll &x : a) cin >> x;

   
    ll beauty0 = 0, evenCnt = 0;
    for (ll x : a) {
        beauty0 += pc(x);
        if (!(x & 1)) ++evenCnt;
    }

    ll best = beauty0 + min<ll>(k, evenCnt);  

    
    for (int i = 0; i < n; ++i) {
        bool wasEven = !(a[i] & 1);
        ll cheapUsed = min<ll>(k, evenCnt - wasEven);    
        ll rem       = k - cheapUsed;                    

        ll base = beauty0 - pc(a[i]);                   
        int origPc = pc(a[i]);

        for (int m = 1; m <= 60; ++m) {                 
            ll target = (1LL << m) - 1;
            if (target < a[i]) continue;                 
            ll cost = target - a[i];
            if (cost > rem) break;                      

            int gain = m - origPc;
            if (gain <= 0) continue;                    

            ll cand = base + m + cheapUsed;              
            best = max(best, cand);
        }
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--) namo();
    return 0;
}
