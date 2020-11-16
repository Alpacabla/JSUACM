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
const int max_n=2e5+5;
ll num[max_n],sum[max_n];
int ind[max_n];
bool cmp(int a,int b)
{
	return num[a]<num[b];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		ll m;
		cin>>n>>m;
		ll k=m/2;
		if(m%2==1){
			k++;
		}
		int ans=-1;
		for(int i=1;i<=n;i++){
			cin>>num[i];
			if(num[i]>=k&&num[i]<=m){
				ans=i;
			}
		}
		//cout<<"yes"<<endl;
		if(ans!=-1){
			cout<<1<<endl;
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++) ind[i]=i;
			sort(ind+1,ind+1+n,cmp);
			for(int i=1;i<=n;i++){
				sum[i]=sum[i-1]+num[ind[i]];
				if(sum[i]>=k&&sum[i]<=m){
					ans=i;
				}
				//cout<<sum[i]<<" ";
				//cout<<ind[i]<<" ";
			}
			//cout<<endl;
			if(ans!=-1){
				cout<<ans<<endl;
				for(int i=1;i<=ans;i++){
					cout<<ind[i]<<" ";
				}
				cout<<endl;
			}else{
				cout<<-1<<endl;
			}
		}

	}
	return 0;
}