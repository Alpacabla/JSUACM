#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int sum[max_n*2],num[max_n];
int main()
{
	 
	int i,j;
	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int lim=2*k,ans=int_inf;
		memset(sum,0,lim*sizeof(int)+4);
		sum[2]=n;
		sum[lim+1]=-n;
		//memset(book,0,k*sizeof(int)+4);
		
		for(i=0;i<n;i++){
			scanf("%d",num+i);
		}
		int lim1=n/2;
		for(i=0;i<lim1;i++){
			sum[min(num[i],num[n-i-1])+1]--;
			sum[max(num[i],num[n-i-1])+k+1]++;
			sum[num[i]+num[n-i-1]+1]+=1;
			sum[num[i]+num[n-i-1]]-=1;
			//book[min(num[i],num[n-i-1])]++;
			//sum[num[i]+num[n-i-1]]++;
		}
		//lim1=k/2;
		int cur=0;
		for(i=2;i<=lim;i++){
			//cout<<sum[i]<<endl;
			cur+=sum[i];
			ans=min(ans,cur);
		}
		cout<<ans<<endl;
	}
	return 0;
}