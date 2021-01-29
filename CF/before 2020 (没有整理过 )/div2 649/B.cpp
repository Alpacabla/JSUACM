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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n,m;
	cin>>t;
	while(t--){
		cin>>n;
		//num[0]=0;
		num[n+1]=0;
		for(i=1;i<=n;i++){
			cin>>num[i];
		}
		int flag=0;
		int cnt=0;
		if(num[1]<num[2]){
			flag=1;
		}else{
			flag=0;
		}
		vector<int>ans;
		for(i=1;i<n;i++){
			if(num[i]<num[i+1]){
				if(flag){
					flag=0;
					ans.push_back(num[i]);
				}
			}else{
				if(!flag){
					flag=1;
					ans.push_back(num[i]);
				}
			}
		}
		ans.push_back(num[n]);
		cout<<ans.size()<<endl;
		for(i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}