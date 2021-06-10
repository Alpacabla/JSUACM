// Problem: D. Another Problem About Dividing Numbers
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/contest/1538/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int max_n=1e5+5;
int pri[max_n],tot;
bool vis[max_n];
void init(int n)
{
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&1ll*pri[j]*i<=n;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0) break;
		}
	}
}
int solve(int num)
{
	int res=0;
	for(int i=0;i<tot&&1ll*pri[i]*pri[i]<=num;i++){
		while(num%pri[i]==0){
			num/=pri[i];
			res++;
		}
	}
	return res+(num!=1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	init(1e5);
	cin>>t;
	while(t--){
		int a,b,k;
		cin>>a>>b>>k;
		int cnt=0;
		cnt+=solve(a);
		cnt+=solve(b);
		if((a==b&&k==1)||(a!=b&&k==0)||((a%b!=0&&b%a!=0&&k==1))){
			cout<<"NO"<<endl;
		}else{
			if(cnt>=k){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}