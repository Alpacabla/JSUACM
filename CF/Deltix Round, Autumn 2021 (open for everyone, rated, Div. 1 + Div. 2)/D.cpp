// Problem: D. Social Network
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int siz[max_n];
int pa[max_n];
int find(int a){
	return pa[a]?(pa[a]=find(pa[a])):a;
}
bool merge(int a,int b)
{
	a=find(a),b=find(b);
	if(a!=b){
		pa[a]=b;
		siz[b]+=siz[a];
		return true;
	}else return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) siz[i]=1;
	int max1=0,maxnode=0;
	int cnt=0;
	while(d--){
		int a,b;
		cin>>a>>b;
		int out=0;
		if(merge(a,b)){
			if(siz[find(b)]>max1){
				maxnode=find(b);
				max1=siz[find(b)];
			}
		}else{
			cnt++;
		}
		vector<int> vis(n+1),val;
		vis[maxnode]=true;
		for(int i=1;i<=n;i++){
			int v=find(i);
			if(!vis[v]){
				vis[v]=true;
				val.push_back(siz[v]);
			}
		}
		sort(val.begin(),val.end(),greater<int>());
		for(int i=0;i<val.size()&&i<cnt;i++) out+=val[i];
		cout<<max1+out-1<<endl;
	}
	
	
	return 0;
}