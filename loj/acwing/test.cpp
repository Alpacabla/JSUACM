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
int x[max_n],y[max_n];
int ind[max_n];
pair<double,double> get_pair(int x,int y,const int d)
{
	double x1,x2;
	x1=sqrt(1.0*d*d-1.0*y*y);
	x2=-x1;
	if(x1>x2){
		swap(x1,x2);
	}
	return make_pair(x1,x2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,d;
	bool flag=true;
	cin>>n>>d;
	for(i=0;i<n;i++){
		cin>>x[i]>>y[i];
		ind[i]=i;
		if(y[i]>d) flag=false;
	}
	if(!flag) cout<<-1<<endl;
	else{
		vector<pair<double,double> >segs;
		for(i=0;i<n;i++){
			segs.push_back(get_pair(x[i],y[i],d));
		}
		sort(ind,ind+n,[segs](int a,int b) -> bool{
			if((segs[ind[a]]).second==(segs[ind[b]]).second) return (segs[ind[a]]).first<(segs[ind[b]]).first;
			else return (segs[ind[a]]).second<(segs[ind[b]]).second;
		});
		int ans=1;
		int r=segs[ind[0]].second;
		for(i=0;i<n;i++){
			if(segs[ind[i]].first>r){
				r=segs[ind[i]].second;
				ans++;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
