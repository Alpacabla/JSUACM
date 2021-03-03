/*
link: 
tags: 
*/
#include<string>
#include<iostream>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int a[1005],b[1005];
int n;
int le[1005],ri[1005];
int cnt;
int dfs(int l,int r)
{
	int res=0;
	for(int i=l;i<=r;i++){
		if(b[i]==a[cnt]){
			res=cnt;
			cnt++;
			le[res]=dfs(l,i-1);
			ri[res]=dfs(i+1,r);
			break;
		}
	}
	return res;
}
int tot=0;
void out(int now)
{
	if(now!=0){
		out(le[now]);
		out(ri[now]);
		tot++;
		cout<<a[now];
		if(tot!=n) cout<<" ";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	while(cin>>n){
		cnt=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		dfs(1,n);
		tot=0;
		out(1);
		cout<<endl;
	}
	return 0;
}