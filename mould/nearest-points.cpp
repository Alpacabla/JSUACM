/*
link: https://oi-wiki.org/geometry/nearest-points/#_2
link: https://www.luogu.com.cn/problem/P1429
tags: nearest-points 平面最近点对
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
const int max_n=2e5+5;
int n;
double ans;
struct node{
	ll x,y;
	inline void dis(const node &a){
		double t=(a.x-x)*(a.x-x)+(a.y-y)*(a.y-y)+0.0;
		if(t<ans*ans){ ans=sqrt(t);}
	}
}nodes[max_n],nos[max_n];
bool cmp_x(const node &a,const node &b)
{
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
bool cmp_y(const node &a,const node &b)
{
	return a.y<b.y;
}
void find(int s,int e)
{
	if(e-s<=2){
		for(int i=s;i<=e;i++){
			for(int j=i+1;j<=e;j++){
				nodes[i].dis(nodes[j]);
			}
		}
		sort(nodes+s,nodes+e+1,cmp_y);
		return ;
	}
	int mid=(s+e)>>1;
	int midx=nodes[mid].x;
	find(s,mid);
	find(mid+1,e);

	merge(nodes+s,nodes+mid+1,nodes+mid+1,nodes+e+1,nos,cmp_y);
	memcpy(nodes+s,nos,sizeof(node)*(e-s+1));

	int tot=e-s+1;
	int start=0;
	for(int i=1;i<=tot;i++){
		 if(abs(nos[i].x-midx)<ans){
		 	while(start!=i&&nos[i].y-nos[start].y>ans) start++;
		 	for(int j=start;j<i;j++){
		 		nos[i].dis(nos[j]);
		 	}
		 }
	}

	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	ans=1e9;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>nodes[i].x>>nodes[i].y;
	}
	sort(nodes,nodes+n,cmp_x);
	find(0,n-1);
	cout<<fixed<<setprecision(4)<<ans<<endl;
	return 0;
}
