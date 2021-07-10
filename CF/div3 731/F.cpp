// Problem: F. Array Stabilization (GCD version)
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e3+5;
int pri[max_n],tot;
bool vis[max_n];
void init(const int n)
{
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0) break;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	init(1e3);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		int g=a[0];
		for(int i=0;i<n;i++){
			g=__gcd(g,a[i]);
		}
		for(int i=0;i<n;i++){
			a[i]/=g;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<tot&&pri[j]*pri[j]<=a[i];j++){
				if(a[i]%pri[j]==0){
					int k=i;
					int len=0;
					while(1){
						if(a[k%n]%pri[j]) break;
						while(a[k%n]%pri[j]==0) a[k%n]/=pri[j];
						len++;
						k++;
					}
					k=i-1;
					while(1){
						if(a[(k+n)%n]%pri[j]) break;
						while(a[(k+n)%n]%pri[j]==0) a[(k+n)%n]/=pri[j];
						len++;
						k--;
					}
					ans=max(ans,len);
				}
			}
			if(a[i]!=1){
				int z=a[i];
				if(a[i]%z==0){
					int k=i;
					int len=0;
					while(1){
						if(a[k%n]%z) break;
						while(a[k%n]%z==0) a[k%n]/=z;
						len++;
						k++;
					}
					k=i-1;
					while(1){
						if(a[(k+n)%n]%z) break;
						while(a[(k+n)%n]%z==0) a[(k+n)%n]/=z;
						len++;
						k--;
					}
					ans=max(ans,len);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}