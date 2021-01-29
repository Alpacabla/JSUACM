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
struct nodes{
	int ver,len;
};
bool vis[max_n];
int disa[max_n],disb[max_n],disc[max_n];
int num[max_n];
ll sum[max_n];
int head[max_n],to[max_n<<1],nxt[max_n<<1],cnt;
inline void add(int a,int b)
{
	nxt[++cnt]=head[a],head[a]=cnt,to[cnt]=b;
	return ;
}
void init(int m,int n)
{
	memset(head,0,(n+2)*sizeof(int));
	memset(disb,0,(n+2)*sizeof(int));
	memset(disc,0,(n+2)*sizeof(int));
	memset(disa,0,(n+2)*sizeof(int));
	cnt=0;
	int i;
	for(i=1;i<=m;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+m);
	for(i=1;i<=m;i++){
		sum[i]=sum[i-1]+(ll)num[i];
	}
	for(i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	return ;
}
void bfs(int *dis,int start,int n)
{
	memset(vis,0,(n+2));
	nodes t;
	t.ver=start;
	t.len=0;
	vis[t.ver]=true;
	queue<nodes>q;
	q.push(t);
	while(!q.empty()){
		t=q.front();
		q.pop();
		dis[t.ver]=t.len;
		for(int i=head[t.ver];i;i=nxt[i]){
			if(!vis[to[i]]){
				vis[to[i]]=true;
				q.push((nodes){to[i],t.len+1});
			}
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n,m,a,b,c;
	cin>>t;
	while(t--){
		cin>>n>>m>>a>>b>>c;
		init(m,n);
		bfs(disa,a,n);
		bfs(disb,b,n);
		bfs(disc,c,n);
		ll ans=ll_inf;
		for(i=1;i<=n;i++){
			if(disa[i]+disb[i]+disc[i]>m) continue;		//减掉是最好的可能会到两倍的n
			ans=min(ans,sum[disa[i]+disb[i]+disc[i]]+sum[disb[i]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}