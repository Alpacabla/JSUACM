// Problem: D1. Mocha and Diana (Easy Version)
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/D2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int pa1[max_n],pa2[max_n];
int find(int *pa,int a){
	return pa[a]?pa[a]=find(pa,pa[a]):a;
}
bool merge(int a,int b)
{
	int a1=find(pa1,a),b1=find(pa1,b);
	if(a1!=b1){
		int a2=find(pa2,a),b2=find(pa2,b);
		if(a2!=b2){
			pa1[a1]=b1;
			pa2[a2]=b2;
			return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1+m2;i++){
		int a,b;
		cin>>a>>b;
		int *pa;
		if(i<=m1){
			pa=pa1;
		}else{
			pa=pa2;
		}
		a=find(pa,a);
		b=find(pa,b);
		if(a!=b){
			if(a==1) swap(a,b);
			pa[a]=b;
		}
	}
	vector<pair<int,int> > ans;
	for(int i=2;i<=n;i++){
		if(merge(i,1)){
			ans.push_back(make_pair(1,i));
		}
	}
	stack<int> sta;
	for(int i=2;i<=n;i++){
		if(pa1[i]==0){
			sta.push(i);
		}
	}
	for(int i=2;i<=n;i++){
		if(pa2[i]==0){
			if(sta.size())
				ans.push_back(make_pair(sta.top(),i)),sta.pop();
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	return 0;
}