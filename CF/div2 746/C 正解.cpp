// Problem: C. Bakry and Partitioning
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/C
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
const int max_n=1e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int val[max_n];
int xorsum;
bool ans;
int cnt;
int dfs(int a,int pa)
{
	int v=val[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa){
			v^=dfs(u,a);
		}
	}
	if(v==xorsum){
		v=0;
		cnt++;
	}
	return v;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		
		xorsum=0;
		for(int i=1;i<=n;i++){
			cin>>val[i];
			xorsum^=val[i];
			head[i]=0;
		}
		tot=1;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
		}
		ans=false;
		if(xorsum==0){
			ans=true;
		}else{
			if(k!=2){
				cnt=0;
				dfs(1,0);
				ans=(cnt>=3?true:false);
			}
		}
		cout<<(ans?"YES":"NO")<<endl;
	}
	return 0;
}