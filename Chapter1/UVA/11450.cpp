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
int M,C;
int arr[21][21];
int dp[21][205];
int rec(int i,int M)
{
  if(i==C)
    return 0;
  if(dp[i][M]!=-1)
    return dp[i][M];
  int res=-1e9;
  for(int j=0;j<21;j++)
  {
    if(arr[i][j]==-1)
      break;

    if(M-arr[i][j]>=0)
    res=max(res,rec(i+1,M-arr[i][j])+arr[i][j]);
  }
  return dp[i][M]=res;
}
int32_t main()
{
ios_base::sync_with_stdio(false);
   cin.tie(NULL);
//   freopen("haircut.in","r",stdin);
// freopen("haircut.out","w",stdout);


int tt=1;
cin>>tt;
int T=1;
while(tt--)
{
for(int i=0;i<21;i++)
{
  for(int j=0;j<21;j++)
    arr[i][j]=-1;
}
for(int i=0;i<21;i++)
{
  for(int j=0;j<201;j++)
    dp[i][j]=-1;
}
cin>>M>>C;
for(int i=0;i<C;i++)
{
  int N;
  cin>>N;
  for(int j=0;j<N;j++)
  {
    cin>>arr[i][j];
  }
}
int x=rec(0,M);
// cout<<x<<"\n";
if(x<0)
  cout<<"no solution"<<"\n";
else cout<<x<<"\n";
// cout<<rec(0,M)<<"\n";

}

}

/*stolen stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/