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
bool vis[600][600];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(i=1;i<=n;i++){
		vis[i+1][i]=1;
		vis[i-1][i]=1;
		vis[i][i]=1;
		vis[i][i+1]=1;
		vis[i][i-1]=1;
	}
	int cnt=2;
	vector<pair<int,int> >ans;
	ans.push_back(make_pair(0,0));
	ans.push_back(make_pair(n+1,n+1));
	for(i=0;i<600;i++){
		for(j=0;j<600;j++){
			if(vis[i]00[j]){
				cnt++;
				ans.push_back(make_pair(i,j));
			}
		}
	}
	cout<<cnt<<endl;
	for(i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;

	}
	return 0;
}