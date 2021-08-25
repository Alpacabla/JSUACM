#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=4e4+5;


bool vis[16][max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<string> ss(n+1);
	for(int i=1;i<=n;i++) cin>>ss[i];
	
	vector<vector<int> > max1(n+1);
	vector<vector<int> > dp(n+1);
	vector<vector<string> > s(n+1,vector<string>(0));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<(1<<(int)ss[i].size());j++){
			int v=j;
			string ts;
			for(int l=0;l<ss[i].size();l++){
				if(((v>>l)&1)==1){
					ts+=ss[i][l];
				}
			}
			s[i].push_back(ts);
		}
		sort(s[i].begin(),s[i].end());
		vector<int> ddp(s[i].size());
		dp[i]=ddp;
	}
	
	int ans=0;
	
	for(int i=0;i<s[1].size();i++){
		dp[1][i]=s[1][i].size();
	}
	
	vector<int> sufmax(s[1].size());
	sufmax[0]=s[1][0].size();
	for(int j=1;j<s[1].size();j++){
		sufmax[j]=max((int)s[1][j].size(),sufmax[j-1]);
	}
	max1[1]=sufmax;
	
	
	
	for(int i=2;i<=n;i++){
		
		for(int j=0;j<s[i].size();j++){
			int k=(int)(lower_bound(s[i-1].begin(),s[i-1].end(),s[i][j])-s[i-1].begin());
			if(k==0){
				//vis[i][j]=true;
				//cant
			}else{
				if(max1[i-1][k-1]!=0){
					dp[i][j]=s[i][j].size()+max1[i-1][k-1];
				}
				// else{
					// vis[i][j]=true;
				// }
			}
		}
		
		vector<int> sufmax(s[i].size());
		sufmax[0]=dp[i][0];
		for(int j=1;j<s[i].size();j++){
			sufmax[j]=max((int)dp[i][j],sufmax[j-1]);
		}
		max1[i]=sufmax;
	}
	for(int i=0;i<s[n].size();i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<(ans?ans:-1)<<endl;
	
	return 0;
}