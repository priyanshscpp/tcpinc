#include <bits/stdc++.h>
using namespace std;
      
/* OM NAMO NARAYANA */
/* Code written by Priyanshu Yadav  */

/* TYPES  */
#define int long long
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

string to_upper(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

/* clang-format on */

void namo(){


}

/* Main()  function */
signed main()
{

      int n,m,k; cin>>n>>m>>k;
    int a[n+1]; for(int i=1;i<=n;i++) cin>>a[i];
	int l[m+1],r[m+1],x[m+1];
	for(int i=1;i<=m;i++) cin>>l[i]>>r[i]>>x[i];
	int cnt[m+2]={};
	while(k--)
	{
		int x,y; cin>>x>>y;
		cnt[x]++;
		cnt[y+1]--;
	}
	for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
	int dif[n+2]={};
	for(int i=1;i<=m;i++)
	{
		dif[l[i]]+=cnt[i]*x[i];
		dif[r[i]+1]-=cnt[i]*x[i];
	}
	for(int i=1;i<=n;i++) {dif[i]+=dif[i-1];a[i]+=dif[i];}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';


    
}


