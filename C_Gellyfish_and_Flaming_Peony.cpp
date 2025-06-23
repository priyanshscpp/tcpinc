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


/* Main()  function */
int main()
{

   ll t;
     cin>>t;
while(t--){
  int n; 
        cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        
        int g = a[0];
        for(int i = 1; i < n; i++){
            g = gcd(g, a[i]);
        }

        
        int cnt = 0;
        for(int x : a){
            if(x == g) cnt++;
        }
        if(cnt > 0){
            cout << (n - cnt) << "\n";
            continue;
        }

      
        vi b(n);
        for(int i = 0; i < n; i++){
            b[i] = a[i] / g;
        }

       
       vi vals = b;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = (int)vals.size();

       
        const int INF = 0x3f3f3f3f;
        static int dist[5001];
        for(int i = 0; i <= 5000; i++){
            dist[i] = INF;
        }

      
        queue<int> q;
        for(int u : vals){
            if(dist[u] > 1){
                dist[u] = 1;
                q.push(u);
            }
        }

      
        while(!q.empty()){
            int v = q.front(); 
            q.pop();
            int dv = dist[v];
            for(int u : vals){
                int w = gcd(v, u);
                if(dist[w] > dv + 1){
                    dist[w] = dv + 1;
                    q.push(w);
                }
            }
        }

      
        int k = dist[1];
       
        int ans = n + k - 2;
        cout << ans << endl;


}

    return 0;
}


