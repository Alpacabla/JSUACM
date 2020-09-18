/*
link: https://codeforces.com/contest/1406/problem/C
tags: tree 重心
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
int head[max_n],to[max_n<<1],nxt[max_n<<1],ind;
inline void add(int a,int b){
	to[++ind]=b;
	nxt[ind]=head[a];
	head[a]=ind;
	return ;
}
int cnt[max_n];
int dfs(int a,int fa)
{
	int i;
	cnt[a]=1;
	for(i=head[a];i;i=nxt[i]){
		if(to[i]!=fa){
			cnt[a]+=dfs(to[i],a);
		}
	}
	return cnt[a];
}
int x,y;
int flag;
int min1;
int tsize;
void findmin(int a,int fa)
{
	int i;
	int max1=-1;
	for(i=head[a];i;i=nxt[i]){
		if(to[i]!=fa){
			max1=max(max1,cnt[to[i]]);
			findmin(to[i],a);
		}else{
			if(fa!=-1) 	max1=max(max1,tsize-cnt[a]);
		}
	}
	min1=min(min1,max1);
	return ;
}
void find1(int a,int fa)
{
	if(flag==2) return ;
	int i;
	int max1=-1;
	for(i=head[a];i;i=nxt[i]){
		if(to[i]!=fa){
			max1=max(max1,cnt[to[i]]);
			find1(to[i],a);
		}else{
			if(fa!=-1) 	max1=max(max1,tsize-cnt[a]);
		}
	}
	if(max1==min1){
		flag++;
		if(flag==1){
			x=a;
		}else y=a;
		if(flag==2) return ;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	int n;
	while(t--){
		ind=1;
		cin>>n;
		tsize=n;
		for(i=1;i<=n;i++){
			head[i]=0;
		}
		for(i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
		}
		min1=int_inf;
		dfs(1,-1);
		findmin(1,-1);
		flag=0;
		x=-1,y=-1;
		find1(1,-1);
		if(y==-1){
			cout<<1<<" "<<to[head[1]]<<endl;
			cout<<1<<" "<<to[head[1]]<<endl;
		}else{
			int ans;
			for(i=head[y];i;i=nxt[i]){
				if(to[i]!=x){
					ans=to[i];
					break;
				}
			}
			cout<<y<<" "<<ans<<endl;
			cout<<x<<" "<<ans<<endl;
		}
	}
	return 0;
}
