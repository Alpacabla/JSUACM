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
int n;
void pri(int *num,int sz)
{
	for(int i=0;i<sz;i++){
		cout<<(i==0?"":" ")<<num[i];
	}
	cout<<endl;
	return ;
}
void f(int a,int last,int *num)
{
	if(last!=-1){
		pri(num,a);
	}
	for(int i=max(1,last+1);i<=n;i++){
		num[a]=i;
		f(a+1,i,num);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int num[20];
	cin>>n;
	f(0,-1,num);
	cout<<endl;
	return 0;
}