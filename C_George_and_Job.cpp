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
int n, m, k;
ll dp[5001][5001];
ll value[5001];
ll helper(int index, int used_k)
{
	if (index > n)
		return -1e15;
	if (index == n)
	{
		if (used_k == k)
			return 0;
		else
			return -1e15;
	}
	if (dp[index][used_k] != -1)
		return dp[index][used_k];
	if (used_k == k)
		return 0;
	ll ans1 = value[index] + helper(index + m, used_k + 1);
	ans1 = max(ans1, helper(index + 1, used_k));
	dp[index][used_k] = ans1;
	return ans1;
}
void namo(){
    cin>>n>>m>>k;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        if(i+m>n){

            value[i]=-1e15;
            continue;

        }
        ll sum=0;
        for(int j=i; j<i+m; j++)
            sum +=arr[j];
            value[i]=sum;

    }
    for(int i=0; i<=n; i++)
       for(int j=0; j<=k; j++)
          dp[i][j] =-1;
    
  cout<<helper(0,0)<<endl;
  


}

/* Main()  function */
int main()
{

    namo();

    return 0;
}


