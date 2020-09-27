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
int num[max_n];
double sum[max_n];
int n,m;
bool check(double avg)
{
	int i,j;
	sum[0]=0.0;
	for(i=1;i<=n;i++){
		sum[i]=sum[i-1]+(1.0*num[i]-avg);
	}
	double minl=sum[0];
	for(i=1,j=m;j<=n;j++,i++){
		minl=min(minl,sum[i-1]);
		if(sum[j]-minl>=0) return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	cin>>n>>m;
	int max1=-1;
	for(i=1;i<=n;i++){
		cin>>num[i];
		max1=max(max1,num[i]);
	}
	double l=0.9,r=1.0*max1;
	double ans;
	while(r-l>1e-5){
		double mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid;
		else r=mid;
 	}
 	cout<<(int)((ans+1e-6)*1000)<<endl;
	return 0;
}