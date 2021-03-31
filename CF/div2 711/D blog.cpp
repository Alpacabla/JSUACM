// Problem: D. Bananas in a Microwave
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define int ll
struct node{
	int type;
	ll x;
	int y;
};
const int DIV=1e5;
inline int CEIL(ll x){
	return (x+DIV-1)/DIV;
}
#define nxt(zz,k) ((a[k].type==1)?zz+a[k].x/*(int)ceil(a[k].x/1e5)*/:CEIL(a[k].x*zz))
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<node> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].type>>a[i].x>>a[i].y;
		if(a[i].type==1){
			a[i].x=CEIL(a[i].x);
		}
	}
	vector<int> vis(m+1,int_inf),low(m+1,-1);
	vis[0]=0;
	for(int i=0;i<=m;i++){
		if(vis[i]!=int_inf){
			int j,cnt;
			for(j=nxt(i,vis[i]),cnt=low[i]+1;cnt<a[vis[i]].y&&j<=m&&vis[j]==int_inf;j=nxt(j,vis[i]),cnt++){
				vis[j]=vis[i];
				low[j]=cnt;
			}
			if(cnt<a[vis[i]].y&&j<=m){
				if(vis[j]>=vis[i]){
					if(vis[j]>vis[i]){
						vis[j]=vis[i];
						low[j]=cnt;
					}
					else{
						if(low[j]>cnt){
							low[j]=cnt;
						}
					}
				}
			}
			for(int k=vis[i]+1;k<=n;k++){
				for(j=nxt(i,k),cnt=0;cnt<a[k].y&&j<=m&&vis[j]==int_inf;j=nxt(j,k),cnt++){
					vis[j]=k;
					low[j]=cnt;
				}
				if(cnt<a[k].y&&j<=m){
					if(vis[j]>=k){
						if(vis[j]>k){
							vis[j]=k;
							low[j]=cnt;
						}else{
							if(low[j]>cnt){
								low[j]=cnt;
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		// cout<<"cnt"<<i<<" ";
		cout<<(vis[i]==int_inf?-1:vis[i])<<" ";
	}
	cout<<endl;
	return 0;
}
// 2 50
// 1 332577 10
// 1 902047 10