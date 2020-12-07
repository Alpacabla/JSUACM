/*
link: https://codeforces.com/contest/1457/my
tags: 
	  做法来自网上
	  思路是因为数据本身是递增的所以当序列够长（大概是60）的时候
	  一定会有三个连续的最高位1出现，这时候只要一步就可以得到答案。
	  接着小于60的时候写个n^3次方的前缀异或算法，判断以所有数为中点的时候左右连续异或
	  再比较是否满足构成答案，最后判断。
	  记得虽然数据小于1e9但是异或起来会比1e9大
	  所以要么用ll要么最大值设为0x3f3f3f3f，并且切忌这个时候的最大值
	  不能用来加减，只能做比较
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	vector<int> num(n+2);
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	num[0]=-1;
	num[n+1]=0x7f7f7f7f;
	if(n>=65){
		cout<<1<<endl;
	}else{
		vector<int> sum(n+2);
		for(int i=1;i<=n+1;i++){
			sum[i]=sum[i-1]^num[i];
		}
		int ans=int_inf;
		
		for(int i=2;i<=n;i++){
			for(int k=0;k<=n-i;k++){
				for(int j=i;j<=n-k;j++){
					int a=sum[j]^sum[j-i];
					int b=sum[j+k+1]^sum[j];
					if(a<num[j-i]||a>b){
						ans=min(ans,i+k-1);
					}
				}
			}
		}
		if(ans==int_inf){
			cout<<-1<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
	return 0;
}