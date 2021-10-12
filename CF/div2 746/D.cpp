// Problem: D. Hemose in ICPC ?
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/D
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
int query(vector<int> a){
	cout<<"? "<<a.size();
	for(int i=0;i<a.size();i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
	cout.flush();
	int res;
	cin>>res;
	return res;
}
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
bool vis[max_n];
int siz[max_n];
void dfs(int a,int pa)
{
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa&&!vis[u]){
			dfs(u,a);
			siz[a]+=siz[u];
		}
	}
	return ;
}
int max1=int_inf;
int cen;
int last[1005][1005];
bool dp[1005];
vector<int> res;
int k=0;
void get_res(vector<int> &res,int now,vector<pair<int,int> > &v)
{
	int i=(int)v.size()-1;
	
	while(now){
		if(last[i][now]!=now){
			res.push_back(v[i].second);
		}
		now=last[i][now];
		i--;
	}
	return ;
}
int all;
void dfscen(int a,int pa)
{
	vector<pair<int,int> > v;
	if(pa!=-1){
		v.push_back({all-siz[a],pa});
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa&&!vis[u]){
			dfscen(u,a);
			v.push_back({siz[u],u});
		}
	}
	memset(dp,0,(k+4));
	for(int i=0;i<=v.size();i++) memset(last[i],0,sizeof(int)*(k+4));
	dp[0]=true;
	for(int i=0;i<v.size();i++){
		for(int j=k;j>=0;j--){
			last[i][j]=j;
		}
		for(int j=k;j>=v[i].first;j--){
			if(!dp[j]&&dp[j-v[i].first]){
				dp[j]=true;
				last[i][j]=j-v[i].first;
			}
		}
	}
	for(int j=k;j>=0;j--){
		if(dp[j]){
			if(k-j<max1){
				cen=a;
				res.clear();
				max1=k-j;
				get_res(res,j,v);
			}
			break;
		}
	}
	
	
	return ;
}
void dfsq(int a,int pa,vector<int> &q)
{
	q.push_back(a);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=pa){
			dfsq(u,a,q);
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	vector<int> q(n);
	for(int i=0;i<n;i++){
		q[i]=i+1;
	}
	int vv=query(q);
	int now=n;
	int last=1;
	while(1){
		//k=now/2;
		dfs(last,-1);
		all=siz[last];
		k=(all-1)/2;
		if(all==2){
			int ans=0;
			for(int i=head[last];i;i=nxt[i]){
				int &u=to[i];
				if(!vis[u]){
					ans=u;
				}
			}
			cout<<"! "<<last<<" "<<ans<<endl;
			break;
		}
		max1=int_inf;
		cen=0;
		dfscen(last,-1);
		// cout<<k<<endl;
		// cout<<cen<<endl;
		q.clear();
		q.push_back(cen);
		for(int i=0;i<res.size();i++){
			dfsq(res[i],cen,q);
		}
		int temp=query(q);
		if(temp==vv){
			set<int> s;
			for(int i=0;i<res.size();i++) s.insert(res[i]);
			for(int i=head[cen];i;i=nxt[i]){
				if(!vis[to[i]]&&!s.count(to[i])){
					vis[to[i]]=true;
				}
			}
			last=cen;
		}else{
			for(int i=0;i<res.size();i++){
				vis[res[i]]=true;
			}
			last=cen;
		}
	}
	
	
	return 0;
}