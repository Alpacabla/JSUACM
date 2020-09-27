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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> num(n+5),last(n+5),max1(n+5,-1),ans(n+5);
		int flag=true;
		num[0]=num[1];
		for(i=1;i<=n;i++){
			cin>>num[i];
			if(num[i]!=num[i-1]) flag=false;
		}
		if(flag){
			for(i=1;i<=n;i++){
				cout<<(i==1?"":" ")<<num[i];
			}
			cout<<endl;
			continue;
		}
		for(i=1;i<=n;i++){
			if(!last[num[i]]){
				last[num[i]]=i;
				max1[num[i]]=i;
			}else{
				max1[num[i]]=max(max1[num[i]],i-last[num[i]]);
				last[num[i]]=i;
			}
		}
		for(i=1;i<=n;i++){
			if(last[i]){
				if(max1[i]==-1){
					max1[i]=max(last[i],n-last[i]+1);
				}else max1[i]=max(max1[i],n-last[i]+1);
			}
		}
		for(i=1;i<=n;i++){
			if(max1[i]==-1) continue;
			if(ans[max1[i]]){
				continue;
			}else{
				ans[max1[i]]=i;
			}
		}
		int temp=int_inf;
		for(i=1;i<=n;i++){
			if(ans[i]) {temp=min(ans[i],temp);cout<<temp<<" ";}
			else{
				if(temp==int_inf) cout<<-1<<" ";
				else cout<<temp<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
