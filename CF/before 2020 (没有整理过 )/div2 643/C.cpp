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
int num[max_n];
int c,d;
ll f(int l,int r,int len)
{
	int cr=r;
	ll res=0;
	if(r<c){
		return 0;
	}
	if(l>d){
		return 0;
	}
	if(l<c){
		l=c;
	}
	if(r>d){
		r=d;
	}
	res+=(ll)(r-l+1)*len;
	//cout<<"res"<<res<<endl;
	if(cr-len+2<=r){
		int min1=min(r,cr);
		int cnt=min1-(cr-len+2)+1;
		res-=(ll)(cnt+1)*cnt/2;
	}
	if(cr-len+2<=l-1){
		int min1=min(l-1,cr);
		int cnt=min1-(cr-len+2)+1;
		res+=(ll)(cnt+1)*cnt/2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int a,b;
	ll ans=0;
	cin>>a>>b>>c>>d;
	for(i=b;i<=c;i++){
		ans+=f(i,i+b-1,b-a+1);
		//cout<<i<<" "<<i+b-1<<" "<<b-a+1<<endl;
		//cout<<f(i,i+b-1,b-a+1)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}