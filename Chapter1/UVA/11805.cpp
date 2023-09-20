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
int mp2[(int)1e6+4];
int pars[(int)1e6+4];
int premax[(int)1e6+4];
int par(int x)
{
  if(x==pars[x])
    return x;
  return pars[x]=par(pars[x]);
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
  int n;
  cin>>n;
  int arr[n];
  vector<pair<int,pair<int,int>>>ranges;
  vector<pair<int,int>>rangesA;
  map<int,int>mp;
  
  set<int>st;
  for(int i=0;i<n;i++)
  {
    int l,r,a,b;
    cin>>l>>r>>a>>b;
    st.insert(l);
    st.insert(r);
    st.insert(a);
    st.insert(b);
    ranges.push_back({l,{r,i}});
    rangesA.push_back({a,b});
  }
  int q;
  cin>>q;
  int que[q];
  for(int i=0;i<q;i++)
  {
    int x;
    cin>>x;
    que[i]=x;
   st.insert(x);
      // cout<<x<<" ";
    }
  // cout<<"FUCK"<<endl;
  int my=1;
  for(auto i:st)
  {
    mp2[my]=i;
    mp[i]=my++;
  }
  for(int i=0;i<n;i++)
  {
    ranges[i].first=mp[ranges[i].first];
    ranges[i].second.first=mp[ranges[i].second.first];
    rangesA[i].first=mp[rangesA[i].first];
    rangesA[i].second=mp[rangesA[i].second];
  }
  // cout<<"FUCK"<<endl;
  // sort(ranges.begin(),ranges.end());
  // cout<<"FF "<<my<<endl;
  
  for(int i=0;i<=my;i++)
    premax[i]=pars[i]=i;
  // cout<<"FUCK"<<endl;
  for(int i=0;i<n;i++)
  {
    premax[ranges[i].first]=max(premax[ranges[i].first],rangesA[i].second);
  }
  
  // cout<<"FUCK"<<endl;
  for(int i=1;i<=my;i++)
    premax[i]=max(premax[i-1],premax[i]);
  for(int i=0;i<=my;i++)
    pars[i]=premax[i];
 for(int i=0;i<q;i++)
 {
  int x=mp[que[i]];
  cout<<mp2[par(x)]<<" ";
  // cout<<mp2[x]<<" ";
 }
 cout<<"\n";

   


  }
// cout<<res<<"\n"''


}

/*stolen stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/