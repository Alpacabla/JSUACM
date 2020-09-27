/*
link: 
tags: greedy
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
struct node{
	int a,b,c;
};
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
		vector<int> num(n);
		int sum=0;
		for(i=0;i<n;i++){
			cin>>num[i];
			sum+=num[i];
		}
		if(sum%n==0){
			int ave=sum/n;
			int cnt=0;
			vector<node> ans;
			ans.clear();
			for(i=1;i<n;i++){
				if(num[i]%i!=0){
					ans.push_back((node){1,i+1,(i+1-(num[i]%(i+1)))});
					num[0]-=(i+1-(num[i]%(i+1)));
					num[i]+=(i+1-(num[i]%(i+1)));
				}
				ans.push_back((node){i+1,1,(num[i]/i)});
				num[0]+=num[i];
				num[i]=0;
			}
			for(i=1;i<n;i++){
				ans.push_back((node){1,i+1,i+1});
			}
			cout<<ans.size()<<endl;
			for(i=0;i<ans.size();i++){
				cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<endl;
			}
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
