// Problem: D2. Half of Same
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/D2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e6+5;
bool vis[max_n],ok[max_n];
int pri[max_n];
int tot=0;
int solve(vector<int> &a,int k)
{
	int res=1;
	int cnt=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==0) cnt++;
	}
	if(cnt>=k) return int_inf;
	memset(ok,0,sizeof(ok));
	memset(vis,0,sizeof(vis));
	tot=0;
	
	for(int i=2;i<=1e6;i++){
		if(!vis[i]){                                                                                                                                                                                                                                                                                   
			pri[tot++]=i;
			ok[i]=true;
		}
		if(ok[i]){
			int cnt=0;
			for(int j=0;j<a.size();j++){
				if(a[j]%i==0){
					cnt++;
				}
			}
			if(cnt>=k){
				ok[i]=true;
				res=i;
			}else{
				ok[i]=false;
			}
		}
		for(int j=0;j<tot&&pri[j]*i<=2e6;j++){
			vis[pri[j]*i]=true;
			ok[pri[j]*i]|=ok[i];
			if(i%pri[j]==0) break;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		int min1=int_inf;
		sort(a.begin()+1,a.end());
		int ans=-1;
		for(int i=1;i<=n/2+1;i++){
			vector<int> v;
			for(int j=i;j<=n;j++){
				v.push_back(a[j]-a[i]);
			}
			ans=max(ans,solve(v,n/2));
			if(ans==int_inf) break;
		}
		if(ans==int_inf) ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}