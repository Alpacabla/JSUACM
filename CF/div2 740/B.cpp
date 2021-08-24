// Problem: B. Charmed by the Game
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/B
// Memory Limit: 512 MB
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
const int max_n=2e5+5;
bool vis[max_n];
vector<int> ans;
void check(int a,int b,int lena,int lenb)
{
	for(int i=0;i<=lenb;i++){
		int sum=i;
		int k1=a,k2=b;
		k1-=i;
		if(k1<0) continue;
		k2-=(lenb-i);
		if(k2<0) continue;
		
		int v=lena;
		v-=k1;
		if(v<0) continue;
		if(k2==v){
			sum+=v;
			vis[sum]=true;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		memset(vis,0,sizeof(bool)*(a+b+3));
		int n=a+b;
		if(n%2==0){
			check(a,b,n/2,n/2);
		}else{
			check(a,b,n/2,n/2+1);
			check(a,b,n/2+1,n/2);
		}
		ans.clear();
		for(int i=0;i<=(a+b);i++){
			if(vis[i]){
				ans.push_back(i);
			}
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<(i==(int)ans.size()-1?"\n":" ");
		}
	}
	return 0;
}