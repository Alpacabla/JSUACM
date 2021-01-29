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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	ll h,c;

	// int sum=0;
	// for(i=1;i<=100000;i++){
	// 	if(i%2){
	// 		sum+=100000;
	// 	}else{
	// 		sum+=1;
	// 	}
	// 	cout<<sum*1.0/i<<endl;
	// }

	double tem;
	cin>>t;
	while(t--){
		cin>>h>>c>>tem;
		if(c==tem){
			cout<<2<<endl;
			continue;
		}
		if((h+c)*1.0/2>=tem){
			cout<<2<<endl;
			continue;
		}
		if((h+c)%2==0&&(h+c)/2==tem){
			cout<<2<<endl;
			continue;
		}
		if(h==tem){
			cout<<1<<endl;
			continue;
		}
		ll sum=h+c;
		ll l=0,r=1000000000000,mid,res,x;
		while(l<=r){
			mid=(l+r)>>1;
			if(fabs((mid*sum+h*1.0)/(mid*2+1))<=tem){
				//cout<<mid<<endl;
				//cout<<fabs((mid*sum+h*1.0)/(mid*2+1))<<endl;
				r=mid-1;
				res=mid;
			}else{
				l=mid+1;
			}
		}
		double min1=fabs((res*sum+h*1.0)/(res*2+1)-tem);
		double min2=fabs(((res-1)*sum+h*1.0)/((res-1)*2+1)-tem);
		if(min1<min2){
			cout<<res*2+1<<endl;
		}else{
			cout<<(res-1)*2+1<<endl;
		}
	}

	return 0;
}