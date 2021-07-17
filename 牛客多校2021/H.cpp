#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int max_n=5e5+5;
int a[max_n];
int n;
bool vis[max_n];
bool judge(int mod)
{
	stack<int> sta;
	for(int i=1;i<=n;i++){
		if(vis[a[i]%mod]){
			while(sta.size()){
				vis[sta.top()]=false;
				sta.pop();
			}
			return false;
		}
		vis[a[i]%mod]=true;
		sta.push(a[i]%mod);
	}
	while(sta.size()){
		vis[sta.top()]=false;
		sta.pop();
	}
	return true;
}
bool pri[max_n];
void init(int n)
{
	int k=sqrt(n);
	for(int i=2;i<=k;i++){
		if(!pri[i]){
			for(int j=i*i;j<=n;j+=i){
				pri[j]=true;
			}
		}
	}
	return ;
}
int main()
{
	scanf("%d",&n);
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	int max1=-1;
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		max1=max(max1,a[i]);
	}
	int ans=max1+1;
	for(int i=n;i<=max1+1;i++){
		if(judge(i)){
			ans=i;
			break;
		}
	}
	// int ans=max1+1;
	// init(5e5);
	// for(int i=2;i<=max1;i++){
	// 	if(ans<i) break;
	// 	if(!pri[i]){

	// 		int l=max(1,(n+i-1)/i),r=(max1+1)/i,res=max1+1;
	// 		cout<<i<<endl;
	// 		cout<<l<<" "<<r<<endl;
	// 		// if((max1+1)%i!=0) r++;
	// 		while(l<=r){
	// 			int mid=(l+r)>>1;
	// 			if(judge(i*mid)){
	// 				cout<<i<<endl;
	// 				res=i*mid;
	// 				r=mid-1;
	// 			}else{
	// 				l=mid+1;
	// 			}
	// 		}
	// 		cout<<"end"<<endl;
	// 		ans=min(ans,res);
	// 	}
	// }
	printf("%d\n",ans);

	return 0;
}