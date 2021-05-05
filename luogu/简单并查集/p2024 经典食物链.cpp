/*
link: https://www.luogu.com.cn/problem/P2024
tags: 要注意的是这里并不只是有一个并查集，orz卡这个点卡
	  半天，并查集在这里只表示一种关系集合而已，所以可能
	  会有多个。
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
int pa[max_n],val[max_n];
inline int find(int a){
	if(pa[a]){
		int k=find(pa[a]);
		val[a]=(val[a]+val[pa[a]])%3;
		return pa[a]=k;
	}else{
		return a;
	}
}
bool merge(int a,int b,int opt)
{
	int aa=find(a),bb=find(b);
	if(aa==bb){
		if(opt==0){
			return val[a]==val[b];
		}else{
			return (val[a]==2&&val[b]==1)||(val[a]==1&&val[b]==0)||(val[a]==0&&val[b]==2);
		}
	}else{
		val[aa]=((3-val[a])%3+opt)%3;
		pa[aa]=b;
		return true;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int ans=0;
	cin>>n>>m;
	while(m--){
		int a,b,opt;
		cin>>opt>>a>>b;
		if((a==b&&opt==2)||a>n||b>n){
			ans++;
			continue;
		}
		ans+=!merge(a,b,opt-1);
	}
	cout<<ans<<endl;
	return 0;
}