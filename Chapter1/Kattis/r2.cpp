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
vector<vector<int>>edges;
int col[(int)1e5+4];
int par[(int)1e5+4];
int sz=0;
int arr[(int)1e5+4];

void dfs(int x,int p)
{
  if(col[x]==1)
  {
    // cout<<"FF"<<"\n";
    // cout<<par[par[par[x]]]<<"\n";
    int cur=p;
    sz++;
    while(cur!=x)
    {
      // cout<<"FF"<<"\n";
      cur=par[cur];
      sz++;
    }
    // cout<<"FF "<<sz<<" "<<x<<"\n";
    return ;
  }
  if(col[x]==2)
  {
    return;
  }
  col[x]=1;
  par[x]=p;
  dfs(arr[x],x);
  col[x]=2;
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
while(tt--)
{
int x,r;
cin>>r>>x;
cout<<x*2-r<<"\n";

}

}

/*stolen stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/