#include <bits/stdc++.h>
using namespace std;
      
/* OM NAMO NARAYANA */
/* Code written by Priyanshu Yadav  */
/* OS : Arch Linux (Rolling Release) */

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

void namo(){
ll a[200005],b[200005],c[200005],n,m,k,t,x,i,w;    
cin>>w>>k;
for(i=1;i<=w;i++)cin>>c[i];
n=0,m=0;
for(i=1;i<=w;i++){
cin>>x;
if(x==1)a[++n]=c[i];
else b[++m]=c[i];
}
sort(a+1,a+n+1);
sort(b+1,b+m+1);
long long s=0;
for(i=1;i<=n;i++)s+=a[i];
int now=m,cnt=n,ans=1e9;
for(i=1;i<=n+1;i++)
{
while(now>0&&s<k)s+=b[now--],cnt+=2;
if(s>=k)ans=min(ans,cnt);
--cnt,s-=a[i];
}
if(ans>w*3) ans=-1;
cout<<ans<<endl;

}

/* Main()  function */
int main()
{

   ll t;
     cin>>t;
while(t--){
  namo();


}

    return 0;
}


