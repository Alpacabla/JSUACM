/*
link: https://ac.nowcoder.com/discuss/557636
 	  https://ac.nowcoder.com/acm/problem/111975
tags: 点连区间 区间连点，做法是用线段树优化，上部分线段树是点到区间的线段树，下部分是区间是到点的线段树，是一个对称的
	  线段树，然后再在对称的线段树构成的有向图上跑dijsktra就行了。还要注意两个线段树要连起来，上面线段树连下面的。
	  稍微思考一下就可以发现这个做法优化的正确性（大概。然后复杂度是nlognlogn，并且常数复杂度还挺大的，线段树加dij
	  hoho
*/
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
int tot,head[max_n<<3],to[max_n<<5],nxt[max_n<<5],val[max_n<<5];
ll ans[max_n<<3];
bool vis[max_n<<3];
int out[max_n];
inline void add(int a,int b,int v)
{
	to[++tot]=b;
	val[tot]=v;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int _move;
int cnt=1;
void build(int l,int r,int ind)
{
	if(l==r){
		out[cnt++]=ind;
		add(ind,ind+_move,0);
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,to_l(ind));
	build(mid+1,r,to_r(ind));
	add(ind,to_l(ind),0);
	add(ind,to_r(ind),0);
	add(to_l(ind)+_move,ind+_move,0);
	add(to_r(ind)+_move,ind+_move,0);
	return ;
}
void search1(int l,int r,int ind,int l1,int r1,int v,int u)
{
	if(r<l1||l>r1) return ;
	if(l>=l1&&r<=r1){
		add(u,ind,v);
		return ;
	}
	int mid=(l+r)>>1;
	search1(l,mid,to_l(ind),l1,r1,v,u);
	search1(mid+1,r,to_r(ind),l1,r1,v,u);
	return ;
}
void search2(int l,int r,int ind,int l1,int r1,int v,int u)
{
	if(r<l1||l>r1) return ;
	if(l>=l1&&r<=r1){
		add(ind+_move,u,v);
		return ;
	}
	int mid=(l+r)>>1;
	search2(l,mid,to_l(ind),l1,r1,v,u);
	search2(mid+1,r,to_r(ind),l1,r1,v,u);
	return ;
}
struct node{
	int u;
	ll v;
	bool operator < (const node b) const {
		return v>b.v;
	}
};
void dij(int start)
{
	memset(ans,0x3f,sizeof(ans));
	priority_queue<node > q;
	q.push((node){start,0});
	while(!q.empty()){
		node a=q.top();
		q.pop();
		if(!vis[a.u]){
			ans[a.u]=a.v;
			vis[a.u]=true;
			for(int i=head[a.u];i;i=nxt[i]){
				if(!vis[to[i]]&&ans[a.u]+val[i]<ans[to[i]]){
					ans[to[i]]=ans[a.u]+val[i];
					q.push((node){to[i],ans[to[i]]});
				}
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
	int n,q,s;
	cin>>n>>q>>s;
	_move=(n<<2)+4;
	build(1,n,1);
	while(q--){
		int k;
		int l,r,a,v;
		cin>>k;
		switch(k){
			case 1:
				cin>>l>>r>>v;
				add(out[l],out[r],v);
				break;
			case 2:
				cin>>a>>l>>r>>v;
				search1(1,n,1,l,r,v,out[a]);
				break;
			case 3:
				cin>>a>>l>>r>>v;
				search2(1,n,1,l,r,v,out[a]);
				break;
		}
	}
	dij(out[s]);
	for(int i=1;i<=n;i++){
		cout<<(ans[out[i]]==ll_inf?-1:ans[out[i]])<<" ";
	}
	cout<<endl;
	return 0;
}