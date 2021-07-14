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
const int max_n=1e5+5;
int sg[max_n];
int f;
int get_sg(int a)
{
	if(sg[a]!=-1) return sg[a];
	if(a<f) return sg[a]=0;
	vector<bool> vis(205);
	for(int i=2;i<=a;i++){
		int q=a/i;
		int x=a/q;
		int res=0;
		int k=a%i;
		int d=i-k;
		if(d%2!=0){
			res^=get_sg(q);
		}
		if(k%2!=0){
			res^=get_sg(q+1);
		}
		vis[res]=true;
		if(i!=x){
			res=0;
			k=a%(i+1);
			d=(i+1)-k;
			if(d%2!=0){
				res^=get_sg(q);
			}
			if(k%2!=0){
				res^=get_sg(q+1);
			}
			i=x;
			vis[res]=true;
		}
	}
	int now=0;
	while(vis[now]) now++;
	return sg[a]=now;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	memset(sg,-1,sizeof(sg));
	//sg[1]=0;
	cin>>t>>f;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		int res=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			res^=get_sg(a[i]);
		}
		cout<<(res==0?0:1)<<" ";
	}
	cout<<endl;
	return 0;
}