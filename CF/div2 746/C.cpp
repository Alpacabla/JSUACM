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
ll val[max_n];
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
ll xorsum=0;
ll sum[max_n],topsum[max_n];
void dfs(int a,int pa)
{
	ll v=val[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa){
			dfs(u,a);
			v^=sum[u];
		}
	}
	sum[a]=v;
	topsum[a]=xorsum^v^val[a];
	return ;
}
bool flag[max_n],topflag[max_n];
void dfs1(int a,int pa)
{
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa){
			dfs1(u,a);
			if(!flag[a]) flag[a]=flag[u];
		}
	}
	if(!flag[a]) flag[a]=(sum[a]==xorsum);
	
	return ;
}
bool ans;
void dfs2(int a,int pa,bool ok)
{
	if(!ok){
		ok=(topsum[a]==xorsum);
	}
	int cnt=0;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa){
			dfs2(u,a,ok);
			if(flag[u]) cnt++;
			if(ok&&flag[u]){
				ans=true;
			}
		}
	}
	if(cnt>=2){
		ans=true;
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
		int n,k;
		cin>>n>>k;
		xorsum=0;
		for(int i=1;i<=n;i++){
			cin>>val[i];
			head[i]=0;
			xorsum^=val[i];
		}
		tot=1;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
		}
		
		ans=false;
		memset(sum,0,sizeof(ll)*(n+2));
		memset(topsum,0,sizeof(ll)*(n+2));
		memset(flag,0,sizeof(bool)*(n+2));
		memset(topflag,0,sizeof(bool)*(n+2));

		dfs(1,-1);
		dfs1(1,-1);
		//cout<<"u"<<endl;
		if(xorsum==0){
			ans=true;
		}else{
			if(k!=2){
				int cnt=0;
				for(int i=head[1];i;i=nxt[i]){
					int &u=to[i];
					dfs2(u,1,(xorsum^sum[u])==xorsum);
					if(flag[u]) cnt++;
				}
				if(cnt>=2){
					ans=true;
				}
			}
		}
		cout<<(ans?"YES":"NO")<<endl;
	}
	return 0;
}