#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
const double eps=1e-8;
double dp[1005][1005];
double ans;
double v;
void dfs(double p,double c,double m,double q,int days)
{
	ans+=p*q*days;
	if(c-0<=eps&&m-0<=eps){
		//ans+=p*days;
		return ;
	}
	
	if(c-0>eps){
		if(c-v<=eps) 
			if(m-0<=eps) dfs(p*c,0,0,1,days+1);
			else dfs(p*c,0,m+c/2,q+c/2,days+1);
		else
			if(m-0<=eps) dfs(p*c,c-v,0,q+v,days+1);
			else dfs(p*c,c-v,m+v/2,q+v/2,days+1);
	}
	if(m-0>eps){
		if(m-v<=eps) 
			if(c-0<=eps) dfs(p*m,0,0,1,days+1);
			else dfs(p*m,c+m/2,0,q+m/2,days+1);
		else 
			if(c-0<=eps) dfs(p*m,0,m-v,q+v,days+1);
			else dfs(p*m,c+v/2,m-v,q+v/2,days+1);
	}
	return ;
}
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		double c,m,p;
		cin>>c>>m>>p>>v;
		ans=0.0;
		dfs(1.0,c,m,p,1);
		printf("%.7lf\n",ans);
	}
	return 0;
}