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
//#define endl '\n'
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>m>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(m==0){
			cout<<"NO"<<endl;
			continue;
		}
		sort(a.begin()+1,a.end());
		vector<int> dpl1(n+1),dpr1(n+1);
		vector<int> dp(n+1);
		vector<int> dpl2(n+1),dpr2(n+1);
		int last=a[1];
		dpl1[1]=dpr1[1]=a[1]-1;

		for(int i=2;i<=n;i++){
			int d=a[i]-last-1;
			dpr1[i]=dpr1[i-1]+d;
			if(dpl1[i-1]+1<=d){
				dpl1[i]=d-(dpl1[i-1]+1);
			}else{
				if(dpl1[i-1]==d){
					dp[i]=dp[i-1]+1;
					dpl1[i]=0;
				}else{
					dpl1[i]=dpl1[i-1]-d;
				}
			}
			if(dpl1[i]>0&&dp[i]){
				if(dpl1[i]>=dp[i]){
					dpl1[i]-=dp[i];
					dp[i]=0;
				}else{
					dp[i]-=dpl1[i];
					dpl1[i]=0;

				}
			}
			last=a[i];
		}

		last=a[n];
		dpl2[n]=dpr2[n]=m-a[n];
		if(dpl2[n]!=0) dpl2[n]-=1;
		for(int i=n-1;i>=1;i--){
			int d=last-a[i]-1;
			dpr2[i]=dpr2[i+1]+d;
			dpl2[i]=abs(dpl2[i+1]-d);
			if(dpl2[i]) dpl2[i]-=1;
			last=a[i];
		}
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(dp[i]){
				dpl2[i]=max(0,dpl2[i]-dp[i]);
			}
			if(dpr1[i]<dpl2[i]||dpl1[i]>dpr2[i]) continue;
			flag=true;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}