// Problem: P4145 上帝造题的七分钟 2 / 花神游历各国
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4145
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int pa[max_n];
int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
void merge(int a,int b)
{
	a=find(a),b=find(b);
	if(a!=b) pa[a]=b;
	return ;
}
ll bit[max_n];
void add(int a,ll v)
{
	while(a<max_n){
		bit[a]+=v;
		a+=lowbit(a);
	}
	return ;
}
ll query(int a)
{
	ll res=0;
	while(a){
		res+=bit[a];
		a-=lowbit(a);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		add(i,a[i]);
	}
	int m;
	cin>>m;
	while(m--){
		int k,l,r;
		cin>>k>>l>>r;
		if(l>r) swap(l,r);
		if(k){
			cout<<query(r)-query(l-1)<<endl;
		}else{
			while(l<=r){
				
				ll v=sqrt(a[l]);
				if(v!=a[l]){
					add(l,v-a[l]);
				}
				a[l]=v;
				if(v==1){
					if(l!=1) merge(l-1,l);
				}
				l=find(l)+1;
			}
		}
	}
	return 0;
}