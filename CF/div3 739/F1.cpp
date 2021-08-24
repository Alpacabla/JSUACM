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
// void dfs(string s,int k)
// {
	// int vis[10];
	// int cnt=0;
	// for(int i=0;i<s.size();i++){
		// if(!vis[s[i]]) vis[s[i]]++,cnt++;
		// if(cnt>k){
// 			
		// }
	// }
// }
vector<ll> out[15];
int vis[15];
void dfs(ll val,int last,int k,bool flag)
{
	if(flag)
		out[k].push_back(val);
		//return ;
	//}
	if(val>=1e10) return ;
	for(int i=flag?0:1;i<10;i++){
		int v=last;
		if(!vis[i]) vis[i]++,v++;
		else vis[i]++;
		if(v>k){
			vis[i]--;
			continue;
		}
		dfs(val*10+i,v,k,1);
		vis[i]--;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	dfs(0,0,1,0);
	dfs(0,0,2,0);
	for(int i=1;i<=2;i++){
		sort(out[i].begin(),out[i].end());
	}
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ind=(int)(lower_bound(out[k].begin(),out[k].end(),n)-out[k].begin());
		cout<<out[k][ind]<<endl;
	}
	
	return 0;
}