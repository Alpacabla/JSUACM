// Problem: D. Playoff Tournament
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/D
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
const int max_n=(1<<21)+5;
int sum[max_n];
int flag[max_n];
vector<int> to[25];
int toto[max_n];
void build(int l,int r,int ind,int vv)
{
	if(l==r){
		sum[ind]=1;
		return ;
	}
	to[vv].push_back(ind);
	int mid=(l+r)>>1;
	build(l,mid,to_l(ind),vv-1);
	build(mid+1,r,to_r(ind),vv-1);
	return ;
}
void change(int ind,char ch)
{
	if(ch=='1'){
		sum[ind]=sum[to_r(ind)];
	}
	if(ch=='0'){
		sum[ind]=sum[to_l(ind)];
	}
	if(ch=='?'){
		sum[ind]=sum[to_l(ind)]+sum[to_r(ind)];
	}
	flag[ind]=ch;
	ind>>=1;
	while(ind){
		char ch=flag[ind];
		if(ch=='1'){
			sum[ind]=sum[to_r(ind)];
		}
		if(ch=='0'){
			sum[ind]=sum[to_l(ind)];
		}
		if(ch=='?'){
			sum[ind]=sum[to_l(ind)]+sum[to_r(ind)];
		}
		ind>>=1;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin>>k;
	int n=(1<<k);
	build(1,n,1,k);
	int tot=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<to[i].size();j++){
			toto[tot++]=to[i][j];
		}
	}
	string s;
	cin>>s;
	for(int i=1;i<n;i++){
		change(toto[i],s[i-1]);
	}
	int q;
	cin>>q;
	while(q--){
		int a;
		char ch;
		cin>>a>>ch;
		change(toto[a],ch);
		cout<<sum[1]<<endl;
	}
	return 0;
}