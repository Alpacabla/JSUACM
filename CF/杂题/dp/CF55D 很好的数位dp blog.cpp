/*
link: http://codeforces.com/problemset/problem/55/D
tags: 从这题开始我才发现以前学的 数位dp 都是错的 orz，数位dp 应该是
	  比我想象的更像搜索，然后比较好写的存状态是存从（大到小的）某一位开始的公共
	  前缀信息的状态。比如这题就是存 在某一位时，出现过的数字是某些，然后判断他们
	  是否能被整除很容易可以想到用 （0-9）的 lcm 。存下前缀的数位值对 lcm 求余的结果，
	  用这个结果再对出现过的数字判断就能知道是否整除。可是这样的一个 dp[i][j][k] 
	  i代表在多少位时 j代表前缀出现过哪些数字 k代表这个的求余值 数组会空间超限，
	  对于第二纬度，我们可以不去考虑出现过哪些数字，考虑 lcm 的因子（只有50个），
	  因为前缀出现的数字能组合出的结果只是 lcm 的因子 罢了。
	  如果能整除（前缀的lcm）那么就可以整除前缀中的所有出现过的数了。
	  这样给的启发是，虽然出现的数字是不一样，但是他们的前缀意义是一致的，那么就可以
	  合并。也就是说某些情况下状态意义一致时但是转移超时或者空间超限可以把状态合并到
	  一起。
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
const int max_n=2600;
const int mod=5*7*8*9;
ull pos[max_n];
ull dp[20][60][max_n];
ull x[20];
int LCM(int a,int b){
	return a/__gcd(a,b)*b;
}
ull digdp(vector<int> &a,int now,int prelcm,int premod,bool flag)
{
	if(now<0) return premod%prelcm==0;
	if(!flag&&dp[now][pos[prelcm]][premod]!=-1) return dp[now][pos[prelcm]][premod];
	int lim=flag?a[now]:9;
	ull res=0;
	int lcm;
	for(int i=0;i<=lim;i++){
		if(i!=0) lcm=LCM(prelcm,i);
		else lcm=prelcm;
		res+=digdp(a,now-1,lcm,(premod+i*x[now])%mod,flag&&i==lim);
	}
	return !flag?dp[now][pos[prelcm]][premod]=res:res;
}
ull solve(ull l,ull r)
{
	vector<int> a;
	while(r){
		a.push_back(r%10);
		r/=10;
	}
	ull ans=digdp(a,a.size()-1,1,0,true);
	l--;
	a.clear();
	while(l){
		a.push_back(l%10);
		l/=10;
	}
	ans-=digdp(a,a.size()-1,1,0,true);
	return ans;
}
inline void init()
{
	memset(dp,-1,sizeof(dp));
	for(int i=1,tot=0;i<=mod;i++){
		if(mod%i==0){
			pos[i]=++tot;
		}
	}
	x[0]=1;
	for(int i=1;i<=18;i++){
		x[i]=x[i-1]*10;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	
	int t;
	cin>>t;
	while(t--){
		ull l,r;
		cin>>l>>r;
		cout<<solve(l,r)<<endl;
	}
	return 0;
}