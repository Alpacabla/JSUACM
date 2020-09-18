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
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n;
		int l=1,r=n;
		for(i=1;i<=n;i++){
			cin>>num[i];
		}
		int nowl=0,nowr=0;
		int flag=1;
		int ans1=0,ans2=0,ans=0;
		while(l<=r){
			int now=0;
			if(flag){
				while(now<=nowr&&l<=r){
					now+=num[l];
					//cout<<now<<" "<<nowr<<endl;
					l++;
				}
				nowl=now;
				ans1+=now;
			}else{
				while(now<=nowl&&l<=r){
					now+=num[r];
					r--;
				}
				nowr=now;
				ans2+=now;
			}
			ans++;
			flag=!flag;
		}
		cout<<ans<<" "<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}