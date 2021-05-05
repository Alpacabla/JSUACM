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
const int max_n=3e4+5;
int pa[max_n],hi[max_n],siz[max_n];
int find(int a){
	if(pa[a]){
		int k=find(pa[a]);
		hi[a]+=hi[pa[a]];
		return pa[a]=k;
	}else{
		return a;
	}
}
void merge(int a,int b)
{
	a=find(a),b=find(b);
	if(a!=b){
		pa[a]=b;
		hi[a]=siz[b];
		siz[b]+=siz[a];
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	for(int i=1;i<max_n;i++) siz[i]=1;
	cin>>n;
	while(n--){
		char ch;
		int a,b;
		cin>>ch>>a>>b;
		if(ch=='M'){
			merge(a,b);
		}else{
			if(a==b){
				cout<<0<<endl;
				continue;
			}
			int aa=find(a),bb=find(b);
			if(aa!=bb) cout<<-1<<endl;
			else cout<<abs(hi[a]-hi[b])-1<<endl;
		}
	}
	return 0;
}