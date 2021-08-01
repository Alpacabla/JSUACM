#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> cnt(n);
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			cnt[a]++;
		} 
		vector<int> ans(n);
		vector<bool> vis(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!vis[j]){
					if(j+i<n&&cnt[j+i]){
						cnt[j+i]--;
						vis[j]=true;
						ans[j]=j+i;
						continue;
					}
					if(j-i>0&&cnt[j-i]){
						cnt[j-i]--;
						vis[j]=true;
						ans[j]=j-i;
						continue;
					}
				}
			}
		}
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<(i==ans.size()-1?'\n':' ');
		}
	}
	return 0;
}