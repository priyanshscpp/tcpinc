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

static const int MOD = 998244353;
static const int NMAX = 100000;
int pow2arr[NMAX+1];

void namo(){
 int n; 
        cin >> n;
        vi p(n), q(n), r(n), invp(n), invq(n);

      for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        for(int i = 0; i < n; i++){
            cin >> q[i];
        }
         for(int i = 0; i < n; i++){
            invp[ p[i] ] = i;
            invq[ q[i] ] = i;
        }

        set<int> S;
        for(int i = 0; i < n; i++){
            S.insert(i);
        }
        for(int M = n-1; M >= 0; M--){
            int a = invp[M];
            int b = invq[M];
            int ell = min(a,b);

            auto it = S.lower_bound(ell);
            while(it != S.end()){
                int i = *it;

                int mval = -1;
                if(i >= a){
                    mval = max(mval, q[i - a]);
                }
                if(i >= b){
                    mval = max(mval, p[i - b]);
                }

                r[i] = ( pow2arr[M] + pow2arr[mval] ) % MOD;

                auto nxt = next(it);
                S.erase(it);
                it = nxt;
            }
        }

        for(int i = 0; i < n; i++){
            cout << r[i] << " ";
        }
        cout <<endl;


}

/* Main()  function */
int main()
{

 pow2arr[0] = 1;
    for(int i = 1; i <= NMAX; i++){
        pow2arr[i] = (pow2arr[i-1] * 2) % MOD;
    }

   ll t;
     cin>>t;
while(t--){
  namo();


}

    return 0;
}


