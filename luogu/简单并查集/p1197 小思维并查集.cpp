/*
link: 
tags: 
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
const int max_n=4e5+5;
int pa[max_n];
vector<int> e[max_n];
inline int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
inline bool merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return false;
	pa[a]=b;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		a+=1;
		b+=1;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int k;
	cin>>k;
	vector<int> a(k+1);
	vector<bool> vis(n+1);
	for(int i=1;i<=k;i++){
		cin>>a[i];
		a[i]++;
		vis[a[i]]=true;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		for(auto u:e[i]){
			if(!vis[u]) merge(i,u);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(pa[i]==0) ans++;
	}
	ans-=k;
	vector<int> out(k+1);
	for(int i=k;i>=1;i--){
		out[i]=ans;
		ans++;
		for(auto u:e[a[i]]){
			if(vis[u]) continue;
			if(merge(u,a[i])){
				ans--;
			}
		}
		vis[a[i]]=false;
	}
	out[0]=ans;
	for(int i=0;i<=k;i++){
		cout<<out[i]<<endl;
	}
	return 0;
}