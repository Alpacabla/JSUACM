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
const int max_n=1e5+5;
vector<int> n1,n2;
int dp[15][15];
void init(int a,int b)
{
	// for(int i=0;i<10;i++){
	// 	dp[0][i]=1;
	// }
	// n1.push_back(-1);
	// n2.push_back(-1);
	while(a){
		n1.push_back(a%10);
		a/=10;
	}
	while(b){
		n2.push_back(b%10);
		b/=10;
	}
	return ;
}
//不仅要特判是否可以超过 （opt） 
//还要使用一个不管什么时候都可以满足的来代表是否是 前导0
//数位最好枚举前一位数，这样好写一点，噶噶噶
int digdp(vector<int> &a,int ind,int pre,bool opt)
{
	if(ind==-1) return 1;
	if((dp[ind][pre]&&!opt)) return dp[ind][pre];
	int lim=(opt?a[ind]:9);
	int res=0;
	for(int i=0;i<=lim;i++){
		if(abs(pre-i)>=2){
			if(pre==11&&i==0)
				res+=digdp(a,ind-1,11,(opt&&i==lim));
			else 
				res+=digdp(a,ind-1,i,(opt&&i==lim));
		}
	}
	return (pre==11||opt)?(res):(dp[ind][pre]=res);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int a,b;
	cin>>a>>b;
	a-=1;
	init(a,b);
	int ans1=0;
	int ans2=0;
	if(a==0){
		ans1=1;
	}else{
		ans1=digdp(n1,n1.size()-1,11,1);
	}
	//memset(dp,0,sizeof(0));

	ans2=digdp(n2,n2.size()-1,11,1);
	cout<<ans2-ans1<<endl;
	return 0;
}