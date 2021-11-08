// Problem: G. Banquet Preparations 1
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1),b(n+1);
		vector<int> aa=a,bb=b,out1=a,out2=b;
		ll min1=0,max1=0;
		ll tot=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			
			aa[i]=max(0,a[i]-m);
			bb[i]=b[i]-(m-(a[i]-aa[i]));
			tot+=a[i]+b[i]-m;
			min1+=max(0,a[i]-m);
			int temp=max(0,b[i]-m);
			temp=a[i]-(m-(b[i]-temp));
			max1+=temp;
		}
		
		ll d=tot-2*min1;
		ll sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			if(d>=2){
				ll dd=a[i]-aa[i];
				ll v=min(d/2,dd);
				int temp=aa[i];
				bb[i]-=v;
				aa[i]+=v;
				if(bb[i]<0){
					aa[i]+=bb[i];
					bb[i]=0;
				}
				d-=2*(aa[i]-temp);
				
			}
			sum1+=aa[i],sum2+=bb[i];
			out1[i]=a[i]-aa[i],out2[i]=b[i]-bb[i];
		}
		
		cout<<abs(sum1-sum2)<<endl;
		for(int i=1;i<=n;i++){
			cout<<out1[i]<<" "<<out2[i]<<endl;
		}
	}
	return 0;
}