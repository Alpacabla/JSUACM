// Problem: D1. Two Hundred Twenty One (easy version)
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/D1
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=3e5+5;
int res;
int query(vector<vector<int> > &ind,int d,int l,int r)
{
	int res=0;
	auto k=lower_bound(ind[d].begin(),ind[d].end(),l);
	if(k!=ind[d].end()){
		if(*k<=r) res=*k;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		string s;
		vector<int> a(n+1);
		vector<int> sum1(n+1),sum2(n+1);
		
		vector<vector<int> > ind1[2],ind2[2];
		for(int i=0;i<2;i++){
			ind1[i].resize(2*n+1);
			ind2[i].resize(2*n+1);
		}
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='-') a[i+1]=-1;
			else a[i+1]=1;
		}
		for(int i=1;i<=n;i++){
			if(i%2){
				sum1[i]=a[i]+sum1[i-1];
				sum2[i]=-a[i]+sum2[i-1];
				
				if(a[i]==1) ind1[0][sum1[i]+n].push_back(i);
				else ind1[1][sum1[i]+n].push_back(i);
				
				if(-a[i]==1) ind2[0][sum2[i]+n].push_back(i);
				else ind2[1][sum2[i]+n].push_back(i);
			}else{
				sum1[i]=-a[i]+sum1[i-1];
				sum2[i]=a[i]+sum2[i-1];
				
				if(-a[i]==1) ind1[0][sum1[i]+n].push_back(i);
				else ind1[1][sum1[i]+n].push_back(i);
				
				if(a[i]==1) ind2[0][sum2[i]+n].push_back(i);
				else ind2[1][sum2[i]+n].push_back(i);
			}
		}
		while(q--){
			int a,b;
			int ans=0;
			cin>>a>>b;
			int d;
			if(a%2){
				d=sum1[b]-sum1[a-1];
				if(d){
					if(d%2){
						ans=1;
					}else{
						ans=2;
					}
				}else{
					ans=0;
				}
			}else{
				d=sum2[b]-sum2[a-1];
				if(d){
					if(d%2){
						ans=1;
					}else{
						ans=2;
					}
				}else{
					ans=0;
				}
			}
			if(ans==0){
				cout<<ans<<endl;
				continue;
			}
			stack<int> out;
			if(ans==2){
				out.push(b);
				b--;
			}
			int res;
			if(a%2){
				d=sum1[b]-sum1[a-1];
				
				int v=(d<0?-1:1)*(abs(d)+1)/2;
				res=query(ind1[d<0?1:0],sum1[b]-(d/2)+n,a,b);
				if(res==0) res=query(ind1[d<0?0:1],sum1[b]-(v)+n,a,b);
			}else{
				d=sum2[b]-sum2[a-1];
				
				int v=(d<0?-1:1)*(abs(d)+1)/2;
				res=query(ind2[d<0?1:0],sum2[b]-(d/2)+n,a,b);
				if(res==0) res=query(ind2[d<0?0:1],sum2[b]-(v)+n,a,b);
			}
			out.push(res);
			cout<<out.size()<<endl;
			while(out.size()){
				cout<<out.top()<<" ";
				out.pop();
			}
			cout<<endl;
			
		}
	}
	return 0;
}