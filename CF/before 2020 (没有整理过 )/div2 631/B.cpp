#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
const int max_n=2e5+5;
bool vis1[max_n],vis2[max_n];
int sum1[max_n],sum2[max_n];
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	int n;
	int i,j;
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis1,0,n+2);
		memset(vis2,0,n+2);
		memset(sum1,0,(n+2)*sizeof(int));
		memset(sum2,0,(n+2)*sizeof(int));
		for(i=1;i<=n;i++){
			cin>>num[i];
		}
		int cnt=1;
		for(i=1;i<=n;i++){
			sum1[i]+=sum1[i-1];
			vis1[num[i]]=1;
			while(vis1[cnt]){
				sum1[i]++;
				cnt++;
			}
		}
		cnt=1;
		for(i=n;i>=1;i--){
			sum2[i]+=sum2[i+1];
			vis2[num[i]]=1;
			while(vis2[cnt]){
				sum2[i]++;
				cnt++;
			}
		}
		cnt=0;
		vector<int>ans;
		for(i=1;i<n;i++){
			if(sum1[i]==i&&sum2[i+1]==n-i){
				cnt++;
				ans.push_back(i);
			}
		}
		cout<<cnt<<endl;
		for(i=0;i<ans.size();i++){
			cout<<ans[i]<<" "<<n-ans[i]<<endl;
		}
	}
	return 0;
}