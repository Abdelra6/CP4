// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l,int r)
{
    uniform_int_distribution<int>uid(l,r);
    return uid(rng);
}
long long mod=(long long)(1e9+7);
long long mul(long long a,long long b)
{
  return (a*b)%mod;
}

long long fstpow(long long x,long long y)
{
  if(y==0)
    return 1;
  long long res=fstpow(x,y/2);
  if(y%2==0)
    return mul(res,res);
  else return mul(res,mul(res,x));
}
int d,n;
int pre[1030][1030];
int get_sum(int l,int r,int ll,int rr)
{

return pre[ll][rr]-(l-1>=0?pre[l-1][rr]:0)-(r-1>=0?pre[ll][r-1]:0)+((l-1>=0&&r-1>=0)?pre[l-1][r-1]:0);
}

int32_t main()
{
ios_base::sync_with_stdio(false);
   cin.tie(NULL);
//   freopen("haircut.in","r",stdin);
// freopen("haircut.out","w",stdout);


int tt=1;
// cin>>tt;
int T=1;
while(true)
{
 int n,m;
 cin>>n>>m;
 if(n==0&&m==0)
  break;
 vector<int>arr(n);
 vector<int>arr2(m);
 for(int i=0;i<n;i++)
  cin>>arr[i];
for(int i=0;i<m;i++)
  cin>>arr2[i];
int res=0;
sort(arr.begin(),arr.end());
// reverse(arr.begin(),arr.end());
sort(arr2.begin(),arr2.end());
int l=0;
for(int i=0;i<m;i++)
{
  if(arr2[i]>=arr[l])
  {
    l++;
    res+=arr2[i];
    if(l==n)
      break;
  }
}
if(l==n)
{
  cout<<res<<"\n";
}
else {
  cout<<"Loowater is doomed!"<<"\n";
}
}

}

/*stolen stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/