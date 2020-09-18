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
bool vis[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int max1=-1;
		vector<int>ans;
		ans.clear();
		memset(vis,0,sizeof(bool)*(n+3));
		for(i=0;i<n;i++){
			cin>>num[i];
			max1=max(max1,num[i]);
		}
		for(i=0;i<n;i++) if(num[i]==max1){ vis[i]=true;break; }
		ans.push_back(num[i]);
		for(i=1;i<n;i++){
			for(j=0;j<n;j++) if(!vis[j]) break;
			int temp=j;
			int maxx=__gcd(num[temp],max1);
			for(j=temp+1;j<n;j++){
				if(!vis[j]){
					if(__gcd(num[j],max1)>maxx){
						maxx=__gcd(num[j],max1);
						temp=j;
					}
				}
			}
			vis[temp]=true;
			max1=maxx;
			ans.push_back(num[temp]);
		}
		for(i=0;i<ans.size();i++){
			cout<<(i==0?"":" ")<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}