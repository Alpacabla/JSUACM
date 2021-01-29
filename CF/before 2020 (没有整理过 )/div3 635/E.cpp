#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+6;
int cnt[205][max_n];
int num[max_n];
vector<int>ind[205];
int get_max(int l,int r)
{
	if(l>r) return 0;
	int i,res=0;
	for(i=1;i<=200;i++){
		res=max(res,cnt[i][r]-cnt[i][l-1]);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=1;j<=200;j++){
				cnt[j][i]=0;
			}
		}
		for(j=1;j<=200;j++) ind[j].clear();
		for(i=1;i<=n;i++){
			cin>>num[i];
			for(j=1;j<=200;j++){
				cnt[j][i]+=cnt[j][i-1];
			}
			cnt[num[i]][i]++;
			ind[num[i]].push_back(i);
		}
		int ans=1;
		for(i=1;i<=200;i++){
			for(j=0,l=ind[i].size()-1;j<l;j++,l--){
				ans=max(ans,(j+1)*2+get_max(ind[i][j]+1,ind[i][l]-1));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}