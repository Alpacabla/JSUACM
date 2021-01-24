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
int a[10];
int n;
bool flag;
void dfs(int last,int cnt,int lim,int sum)
{
	if(flag){
		return ;
	}
	if(cnt==lim){
		if(sum==n){
			flag=true;
			return ;
		}
	}
	for(int i=last+1;i<10&&!flag;i++){
		a[cnt]=i;
		dfs(i,cnt+1,lim,sum+i);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int num[10];
	int sum[10];
	for(int i=0;i<10;i++){
		num[i]=i;
	}
	sum[0]=0;
	for(int i=1;i<=9;i++){
		sum[i]=sum[i-1]+num[10-i];
	}
	cin>>t;
	while(t--){
		cin>>n;
		if(n>45){
			cout<<-1<<endl;
		}else{
			int lim=0;
			for(int i=1;i<10;i++){
				if(n<=sum[i]){
					lim=i;
					break;
				}
			}
			flag=false;
			dfs(0,0,lim,0);
			for(int i=0;i<lim;i++){
				cout<<a[i];
			}
			cout<<endl;
		}
	}
	return 0;
}