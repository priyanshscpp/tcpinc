#include <bits/stdc++.h>
using namespace std;
      
/* OM NAMO NARAYANA */
/* Code written by Priyanshu Yadav  */
/* Operating System : Ubuntu LTS 24.04  */

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
ll a[5009];
ll b[5009];
ll dp[5009][5009];
ll dpp(ll i, ll j ){
    if(i>j)return 0;
    if(i==j)return a[i]*b[j];
    if(dp[i][j] !=-1) return dp[i][j];
    return dp[i][j]=dpp(i+1,j-1)+a[i]*b[j]+a[j]*b[i];

}


/* Main()  function */
signed  main()
{
ll n;cin>>n;
memset(dp,-1,sizeof(dp));
for(int i=1;i<=n; i++)cin>>a[i];
for(int i=1; i<=n; i++)cin>>b[i];
int ans=0, to=0;
for(int i=1; i<=n; i++){
    to +=(a[i]*b[i]);

}
ans=to;
for(int i=1; i<=n; i++){
    int z=0; 
    for(int j=i; j<=n; j++){
        z +=(a[j]*b[j]);
        ans=max(ans,to -z+dpp(i,j));

    }

}
cout<<ans<<endl;


    return 0;
}


