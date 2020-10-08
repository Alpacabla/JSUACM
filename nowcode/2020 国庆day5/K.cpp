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
int x[1005],y[1005];
bool judge(int a,int b,int c,int s,int e)
{
	int res=c%(e-s);
	if((c/(e-s))%2==0){
		res=res+s;
	}else res=e-res;
	if(res<=b&&res>=a) return true;
	else return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		int ans=0;
		for(i=0;i<n;i++){
			ans+=judge(a,b,c,x[i],y[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
