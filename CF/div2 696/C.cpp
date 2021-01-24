#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e6+5;
int vis[max_n];
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
		n<<=1;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a.begin()+1,a.end());
		vector<int> a1,a2;
		bool flag=false;
		for(int i=1;i<=n-1;i++){
			a1.clear(),a2.clear();
			for(int j=1;j<=n;j++) vis[a[j]]++;
			vis[a[n]]--;
			vis[a[i]]--;
			a1.push_back(a[n]);
			a2.push_back(a[i]);
			int now=n;
			int last=a[n];
			for(j=2;j<=n/2;j++){
				while(!vis[a[now]]) now--;
				int max1=a[now];
				vis[max1]--;
				vis[last-max1]--;
				if(vis[max1]>=0&&vis[last-max1]>=0){
					a1.push_back(max1);
					a2.push_back(last-max1);
					last=max1;
				}else{
					vis[last-max1]++;
					vis[max1]++;
					break;
				}
			}
			for(int j=1;j<=n;j++) vis[a[j]]=0;
			if(j==n/2+1){
				flag=true;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
			cout<<a1[0]+a2[0]<<endl;
			for(int i=0;i<a1.size();i++){
				cout<<a1[i]<<" "<<a2[i]<<endl;
			}
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}