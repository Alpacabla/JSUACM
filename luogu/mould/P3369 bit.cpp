// Problem: P3369 【模板】普通平衡树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3369
// Memory Limit: 128 MB
// Time Limit: 1000 ms
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
const int max_n=2e7+5;
int bit[max_n];
void add(int a,int val)
{
	while(a<max_n){
		bit[a]+=val;
		a+=lowbit(a);
	}
	return ;
}
int query(int a)
{
	int res=0;
	while(a){
		res+=bit[a];
		a-=lowbit(a);
	}
	return res;
}
int rk(int a)
{
	int res=0;
	int vv=0;
	for(int i=24;i>=0;i--){
		int t=res+(1<<i);
		if(t>=max_n||vv+bit[t]>=a) continue;
		res+=(1<<i);
		vv+=bit[t];
	}
	return res+1-(int)1e7-2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--){
		int opt,num;
		cin>>opt>>num;
		switch(opt){
			case 1:{
				add(num+1e7+2,1);
				break;
			}
			case 2:{
				add(num+1e7+2,-1);
				break;
			}
			case 3:{
				cout<<query(num+1e7+2-1)+1<<endl;
				break;
			}
			case 4:{
				cout<<rk(num)<<endl;
				break;
			}
			case 5:{
				cout<<rk(query(num+1e7+2-1))<<endl;
				break;
			}
			case 6:{
				cout<<rk(query(num+1e7+2)+1)<<endl;
				break;
			}
				
		}
	}
	return 0;
}