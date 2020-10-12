#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=5e4+5;
int bit[max_n];
int lim;
int num[max_n<<1];
int query1(int x)
{
	int res=-1;
	while(x){
		res=max(res,bit[x]);
		x-=lowbit(x);
	}
	return res;
}
void updata1(int x,int v)
{
	while(x<=lim){
		bit[x]=max(bit[x],v);
		x+=lowbit(x);
	}
	return ;
}
int query2(int x)
{
	int res=-1;
	while(x<=lim){
		res=max(res,bit[x]);
		x+=lowbit(x);
	}
	return res;
}
void updata2(int x,int v)
{
	while(x){
		bit[x]=max(bit[x],v);
		x-=lowbit(x);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	int max1=-1;
	i=0;
	while(cin>>num[i]){
		max1=max(max1,num[i]);
		i++;
	}
	n=i;
	lim=max1+1;
	int ans1=-1,ans2=-1;
	for(i=0;i<n;i++){
		int t=query1(num[i])+1;
		ans2=max(ans2,t);
		updata1(num[i]+1,t);
	}
	for(i=0;i<=lim;i++) bit[i]=0;
	for(i=0;i<n;i++){
		int t=query2(num[i])+1;
		ans1=max(ans1,t);
		updata2(num[i],t);
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	return 0;
}