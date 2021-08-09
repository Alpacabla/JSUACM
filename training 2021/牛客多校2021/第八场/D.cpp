/*
link: 
tags: a+b=a|b+a&b 简单的式子变换一下就好了
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
	int n;
	cin>>n;
	n-=1;
	vector<int> a(n+1),b(n+1);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]-=a[i];
		if(b[i]<0||(b[i]&a[i])!=b[i]) flag=false;
	}
	ll ans=1;
	for(int i=0;i<=30;i++){
		int res=0;
        int kk1=1,kk2=0;
		for(int j=1;j<=n;j++){
			int k1=(a[j]>>i)&1,k2=(b[j]>>i)&1;
			if(k1==0&&k2==1) flag=false;
			if(k1==1&&k2==0) res++;
            if(k1==1&&k2==1&&kk1==0&&kk2==0) flag=false;
            if(k1==0&&k2==0&&kk1==1&&kk2==1) flag=false;
            kk1=k1,kk2=k2;
		}
		if(res==n) ans*=2;
	}
	if(!flag) ans=0;
	cout<<ans<<endl;
	return 0;
}