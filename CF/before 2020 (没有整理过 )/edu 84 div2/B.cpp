#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int max_n=1e5+5;
int book[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	int n;
	int num;
	int i,j;
	int ans,flag,cnt;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++) book[i]=0;	//王子数组
		ans=-1;
		for(i=0;i<n;i++){
			cin>>cnt;
			flag=1;
			for(j=0;j<cnt;j++){
				cin>>num;
				if(flag&&!book[num]){	//题意模拟
					flag=0;
					book[num]=1;
				}
			}
			if(flag==1){				//任选一个没被配对的
				ans=i+1;
			}
		}
		if(ans==-1){
			cout<<"OPTIMAL"<<endl;
		}else{
			for(i=1;i<=n;i++){
				if(!book[i]) break;
			}
			cout<<"IMPROVE"<<endl<<ans<<" "<<i<<endl;
		}
	}
	return 0;
}