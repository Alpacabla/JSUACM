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
int pa[max_n<<1],siz[max_n<<1],ind[max_n<<1];
ll sum[max_n<<1];
int find(int a){
	if(pa[a]){
		int k=find(pa[a]);
		return pa[a]=k;
	}else{
		return a;
	}
}
void merge(int a,int b)
{
	a=find(ind[a]),b=find(ind[b]);
	if(a!=b){
		pa[a]=b;
		siz[b]+=siz[a];
		sum[b]+=sum[a];
	}
	return ;
}
int tot=max_n;
void add(int a,int b)
{
	int aa=find(ind[a]),bb=find(ind[b]);
	if(aa!=bb){
		ind[a]=tot++;
		pa[ind[a]]=bb;
		siz[bb]++;
		sum[bb]+=a;

		siz[aa]--;
		sum[aa]-=a;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++) siz[i]=1,sum[i]=ind[i]=i,pa[i]=0;
		tot=n+1;
		while(m--){
			int opt;
			int a,b;
			cin>>opt;
			if(opt==1){
				cin>>a>>b;
				merge(a,b);
			}else{
				if(opt==2){
					cin>>a>>b;
					add(a,b);
				}else{
					cin>>a;
					a=find(ind[a]);
					cout<<siz[a]<<" "<<sum[a]<<endl;
				}
			}
		}
	}
	
	return 0;
}