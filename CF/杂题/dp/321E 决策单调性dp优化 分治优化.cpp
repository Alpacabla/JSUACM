// Problem: E. Ciel and Gondolas
// Contest: Codeforces - Codeforces Round #190 (Div. 1)
// URL: https://codeforces.com/contest/321/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=4e3+5;
namespace io{
	const int MAX_SIZE=1<<20;//一次性读取这么多字节
	char buf[MAX_SIZE],*p1=NULL,*p2=NULL;
	#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,MAX_SIZE,stdin),p1==p2))?EOF:*p1++)
	inline int read(){//其他类型也能读，自由发挥，注意读负数需要添加一个判断
		int x=0;char ch=gc();
		while (!isdigit(ch))ch=gc();
		while (isdigit(ch)){x=x*10+(ch^48);ch=gc();}
		return x;
	}
	//快输出用递归
}
int a[max_n][max_n];
int sum[max_n][max_n],lsum[max_n][max_n];
int dp_before[max_n],dp_cur[max_n];
inline int get_sum(int x,int y,int x1,int y1){
	return sum[x1][y1]-sum[x-1][y1]-sum[x1][y-1]+sum[x-1][y-1];
}
inline int get_val(int x,int x1)
{
	//int d=x1-x;
	return lsum[x1][x1]-lsum[x-1][x-1]-get_sum(x,1,x1,x-1);
	
}
inline void init(int n)
{
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			lsum[i][j]=lsum[i-1][j-1]+get_sum(i,1,i,j);
		}
	}
	return ;
}

void div_dp(int l,int r,int optl,int optr)
{
	if(l>r) return ;
	int mid=(l+r)>>1;
	
	if(optl<=0||optr<=0) return ;
	
	int max1=int_inf;
	int k=-1;
	
	int now=get_val(optl,mid);
	
	for(int i=optl;i<=min(mid-1,optr);i++){
		now-=get_sum(i,i,i,mid);
		if(max1>now+dp_before[i]){
			max1=now+dp_before[i];
			k=i;
		}
	}
	
	dp_cur[mid]=max1;
	
	int opt=k;
	div_dp(l,mid-1,optl,opt);
	div_dp(mid+1,r,opt,optr);
	return ;
}
int main()
{
	int n,m;
	n=io::read(),m=io::read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=io::read();
			
	init(n);
	
	for(int i=1;i<=n;i++){
		dp_before[i]=lsum[i][i];
		
	}
	
	for(int i=2;i<=m;i++){
		div_dp(i,n,i-1,n-1);
		for(int j=1;j<=n;j++){
			dp_before[j]=dp_cur[j];
			dp_cur[j]=int_inf;
		}
	}
	
	cout<<dp_before[n]<<endl;
	return 0;
}