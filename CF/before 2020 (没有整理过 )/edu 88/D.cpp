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
int num[max_n];
int max1[max_n][35],max2[max_n][35];
bool vis[65];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int n;
	cin>>n;
	int flag=0;
	for(i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]>=1){
			flag=1;
		}
	}
	if(!flag){
		cout<<0<<endl;
		exit(0);
	}


	for(i=1;i<=n;i++){
		if(num[i]>=1&&!vis[num[i]]){
			vis[num[i]]=1;
		}
		for(j=max(num[i],1);j<=30;j++){
			if(vis[j]){
				int t=0;
				for(k=1;k<=j;k++){
					t=max(max1[i-1][k]+num[i],t);
				}
				max1[i][j]=t;
			}
		}
	}
	for(i=1;i<=30;i++) vis[i]=0;
	for(i=n;i>=1;i--){
		if(num[i]>=1&&!vis[num[i]]){
			vis[num[i]]=1;
		}
		for(j=max(num[i],1);j<=30;j++){
			if(vis[j]){
				int t=0;
				for(k=1;k<=j;k++){
					//cout<<max2[i+1][k]<<endl;
					t=max(max2[i+1][k]+num[i],t);
				}
				max2[i][j]=t;
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++){
		if(num[i]>=1){
			int l=0,r=0;
			for(j=1;j<=num[i];j++){
				l=max(l,max1[i-1][j]);
			}
			for(j=1;j<=num[i];j++){
				//if(i==1) cout<<max2[i+1][j]<<endl;
				r=max(r,max2[i+1][j]);
			}
			//cout<<"i "<<i<<endl;
			//cout<<l<<" "<<r<<endl;
			ans=max(ans,l+r);
		}
	}
	cout<<ans<<endl;
	return 0;
}