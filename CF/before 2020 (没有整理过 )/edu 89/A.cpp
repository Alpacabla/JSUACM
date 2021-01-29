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
int n,m;
int cal(int num)
{
	int k=n-num,j=m-num*2;
	return num+min(k/2,j);
}
bool judge(int mid)
{
	if(mid==0) return true;
	
	int a=cal(mid);
	int b=cal(mid-1);
	//cout<<a<<" "<<b<<endl;
	return b>a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	
	cin>>t;
	while(t--){
		cin>>n>>m;
		//cout<<cal(1)<<cal(0)<<endl;
		//cout<<cal(2)<<cal(3)<<endl;
		int l=0,r=min(n,m/2),ans=r;
		//cout<<l<<" "<<r<<endl;

		while(l<=r){
			int mid=(l+r)>>1;
			//cout<<mid<<endl;
			//cout<<endl;
			if(judge(mid)){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(ans==r) cout<<ans<<endl;
		else{
			if(ans==0) cout<<0<<endl;
			else cout<<cal(ans-1)<<endl;
		}
	}
	return 0;
}