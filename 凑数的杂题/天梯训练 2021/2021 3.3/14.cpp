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
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	vector<double> a(n+1),b(n+1);
	vector<int> ind(n+1);
	for(int i=1;i<=n;i++){
		ind[i]=i;
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(ind.begin()+1,ind.end(),[&a,&b](const int aa,const int bb) -> bool {
		return 1.0*b[aa]/a[aa]>1.0*b[bb]/a[bb];
	});
	double ans=0.0;
	for(int i=1;i<=n;i++){
		if(m>a[ind[i]]){
			ans+=b[ind[i]];
			m-=a[ind[i]];
		}else{
			ans+=b[ind[i]]*1.0/a[ind[i]]*m;
			break;
		}
	}
	printf("%.2lf\n",ans);
	//cout<<setprecision()<<ans<<endl;
	return 0;
}