#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int num[max_n];
int v[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		memset(num,0,(n+2)*4);
		memset(v,0,(n+2)*4);
		for(i=1;i<=n;i++){
			cin>>num[i];
		}
		for(i=2;i<n;i++){
			if(num[i]>num[i-1]&&num[i]>num[i+1]){
				v[i]=1;
			}
		}
		int ans=0,l=n+1-k;
		for(j=n-1,i=1;i<k;j--,i++){
			ans+=v[j+1];
		}
		//cout<<j<<endl;
		int cnt=ans;
		for(;j>=1;j--){
			cnt-=v[j+k-1];
			cnt+=v[j+1];
			if(cnt>=ans){
				l=j;
				ans=cnt;
			}
		}
		cout<<ans+1<<" "<<l<<endl;
	}
	return 0;
}