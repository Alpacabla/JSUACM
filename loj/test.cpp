#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll f[11][160][160],ans;
int num[160],s[160];
int n,k,cnt;
inline void pre()
{
  cnt=0;
  for(register int i=0;i<(1<<n);++i)
  {
  	if(i&(i<<1))continue;
  	int sum=0;
  	for(int j=0;j<n;++j)
  	   if(i&(1<<j))++sum;
  	s[++cnt]=i;
  	num[cnt]=sum;
  }return;
}
inline void dp()
{
  f[0][1][0]=1;
  for(register int i=1;i<=n;++i)
    for(register int j=1;j<=cnt;++j)
      for(register int l=0;l<=k;++l)
  	  if(l>=num[j])
  	  {
  	  	   for(register int t=1;t<=cnt;++t)
  	  	   {
  	  	   	    if(!(s[t]&s[j])&&!(s[t]&
  			    (s[j]<<1))&&!(s[t]&(s[j]>>1)))
  	  	   	    f[i][j][l]+=f[i-1][t][l-num[j]];
  	  	   }
  	  }
  for(register int i=1;i<=cnt;++i)
     ans+=f[n][i][k];
  printf("%lld\n",ans);
  return;
}
inline void input()
{
  scanf("%d%d",&n,&k);
  return;
}
int main()
{
  input();
  pre();
  dp();
  return 0;
} 