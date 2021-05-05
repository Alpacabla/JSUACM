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
const int max_n=1e2+5;
#define eps 1e-8
int x[max_n],y[max_n];
double dis[max_n][max_n];
int pa[max_n];
inline int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
void merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return ;
	pa[a]=b;
	return ;
}
bool judge(int n,double mid)
{
	mid=mid*2.0;
	pa[101]=pa[102]=0;
	for(int i=1;i<=n;i++){
		pa[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(mid-(100-y[i])>eps){
			merge(i,101);
		}
		if(mid-(y[i]-(-100))>eps){
			merge(i,102);
		}
		for(int j=i+1;j<=n;j++){
			if(mid-dis[i][j]>eps){
				merge(i,j);
			}
		}
	}
	return find(101)!=find(102);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	auto get_dis = [](int a,int b) -> double{
		return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
	};
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis[i][j]=get_dis(i,j);
		}
	}
	double l=0.0,r=100.0,res=0.0;
	while(r-l>=eps){
		double mid=(l+r)/2.0;
		if(judge(n,mid)){
			l=mid;
			res=mid;
		}else{
			r=mid;
		}
	}
	cout<<res<<endl;
	return 0;
}