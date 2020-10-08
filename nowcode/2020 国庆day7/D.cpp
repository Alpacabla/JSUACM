/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e6+5;
int sum[max_n];
long double dp[max_n];
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int i,j;
	string s,temp;
	cin>>temp;
	reverse(temp.begin(),temp.end());
	s="0"+temp;
	sum[0]=0;
	for(i=1;i<s.size();i++){
		sum[i]=sum[i-1]+(s[i]=='C');
	}
	long double summ=0.0;
	ll sumw=0,sumc=0;
	dp[0]=0;
	for(i=1;i<s.size();i++){
		if(s[i]=='W'){
			sumw+=i;
			dp[i]+=(long double)sumw;
		}else{
			sumc+=i;
			dp[i]+=(long double)sumc;
			// for(j=1;j<=i;j++){
			// 	dp[i]+=sum[i]-sum[j-1];
			// }
		}
		dp[i]+=summ;
		//dp[i]+=summ;
		// for(j=1;j<i;j++){
		// 	dp[i]+=dp[j];
		// }
		dp[i]/=i*1.0;
		summ+=dp[i];
	}
	dp[s.size()-1]=(long double)(s.size()-1)-dp[s.size()-1];
	printf("%.10Lf\n",dp[s.size()-1]);
	return 0;
}
