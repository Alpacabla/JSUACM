/*
link: https://ac.nowcoder.com/acm/contest/11258/F
tags: 树上滑动窗口 加 贪心 加树dfs序check
	  有点像这题https://codeforces.com/contest/1529/problem/E
	  代码是合成的
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
const int max_n=3e5+5;
int head[max_n],to[max_n<<2],nxt[max_n<<2],tot=1,head1[max_n];
inline void add(int *head,int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
pair<int,int> dfn[max_n];
pair<int,int> last[max_n];
int fa[max_n];
int timer=0;

void dfs1(int a,int pa)
{
	dfn[a].first=++timer;
	for(int i=head1[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa) dfs1(u,a);
	}
	dfn[a].second=timer;
	return ;
}
deque<int> dq;
int ans,cnt;

struct Node
{
    int l, r, mx, add;
}tr[max_n * 4];
 
void pushup(int u) {
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}
 
void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add += root.add, left.mx += root.add;
        right.add += root.add, right.mx += root.add;
        root.add = 0;
    }
}
 
void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, 0, 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
 
void modify(int u, int l, int r, int d)
{
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].mx += d;
        tr[u].add += d;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}
 
int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
 
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int mx = 0;
    if (l <= mid) mx = max(mx, query(u << 1, l, r));
    if (r > mid) mx = max(mx, query(u << 1 | 1, l, r));
    return mx;
}
int n;
int addnode(int a)
{
	int &in=dfn[a].first,&out=dfn[a].second;

	modify(1,in,out,1);
	if(query(1,1,n)>=2){
		int k=dq.front();
		modify(1,dfn[k].first,dfn[k].second,-1);
		dq.pop_front();
		dq.push_back(a);
		return 0;
	}
	dq.push_back(a);
	return 1;
}
void delnode(int a)
{
	int &in=dfn[a].first,&out=dfn[a].second;
	if((dq.front())!=1){
		modify(1,dfn[fa[dq.front()]].first,dfn[fa[dq.front()]].second,1);
		dq.push_front(fa[dq.front()]);
	}
    dq.pop_back(),modify(1,in,out,-1);
}
void dfs(int a,int pa)
{
	if(addnode(a)){
		ans=max(ans,(int)dq.size());
	}
	fa[a]=pa;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa) dfs(u,a);
	}
	delnode(a);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		timer=0;
		tot=1;
		memset(head,0,sizeof(int)*(n+2));
		memset(head1,0,sizeof(int)*(n+2));
		build(1,1,n);
		for(int i=2;i<=n;i++){
			int a,b;
			cin>>a>>b;
			add(head,a,b);
			add(head,b,a);
		}
		for(int i=2;i<=n;i++){
			int a,b;
			cin>>a>>b;
			add(head1,a,b);
			add(head1,b,a);
		}
		deque<int> dd;
		dq.swap(dd);
		ans=0;
		dfs1(1,0);
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}