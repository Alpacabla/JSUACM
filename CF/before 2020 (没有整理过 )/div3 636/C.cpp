#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n;
	int k;
	cin>>t;
	while(t--){
		int max1=-int_inf;
		int flag;
		ll ans=0;
		cin>>n;
		cin>>k;
		max1=max(k,max1);
		if(k<0){
			flag=1;
		}else{
			flag=0;
		}
		for(i=1;i<n;i++){
			cin>>k;
			if(k<0){
				if(flag){
					max1=max(max1,k);
				}else{
					flag=1;
					ans+=max1;
					max1=k;
				}
			}else{
				if(!flag){
					max1=max(max1,k);
				}else{
					flag=0;
					ans+=max1;
					max1=k;
				}
			}
		}
		if(flag){
			if(k<0) ans+=(ll)max1;
		}else{
			if(k>0) ans+=(ll)max1;
		}
		cout<<ans<<endl;
	}
	return 0;
}