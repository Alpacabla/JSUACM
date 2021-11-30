// Problem: D2. Divan and Kostomuksha
// Contest: Codeforces - Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/D2
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e7+5;
int cnt[max_n];
ll dp[max_n];
bool vis[max_n];
int pri[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		//cnt[a[i]]++;
	}
	
	int tot=1;
	pri[0]=1;
	const int lim=max_n-5;
	for(int i=2;i<=lim;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=1;j<tot&&pri[j]*i<=lim;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0) break;
		}
	}
	
	for(int i=1;i<=n;i++){
		int v=sqrt(a[i]);
		for(int j=1;j<=v;j++){
			if(a[i]%j==0){
				cnt[j]++;
				if(a[i]/j!=j) cnt[a[i]/j]++;
			}
		}
	}
	
	// for(int o=1;o<=lim;o++){
		// int &i=o;
		// for(int j=2*i;j<=lim;j+=i){
			// cnt[i]+=cnt[j];
		// }
	// }
	
	ll ans=0;
	dp[1]=n;
	for(int i=1;i<=lim;i++){
		for(int j=0;j<tot&&pri[j]*i<=lim;j++){
			int v=pri[j]*i;
			dp[v]=max(dp[v],dp[i]+(v-i)*1ll*cnt[v]);
		}
	}
	for(int i=1;i<=lim;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}