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
int num[105][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		bool flag=false;
		int ans=0;
		int cnt1=0,cnt2=0;
		int min1=105;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>num[i][j];
				if(num[i][j]<0) {
					cnt1++;
				}
				else cnt2++;
				if(min1>abs(num[i][j])){
					min1=abs(num[i][j]);
				}
				ans+=abs(num[i][j]);
				if(num[i][j]==0){
					flag=true;
				}
			}
		}
		if(flag){
			cout<<ans<<endl;
		}else{
			
			if(cnt1%2==0){
				cout<<ans<<endl;
			}else{
				cout<<ans-2*min1<<endl;

			}
		}
	}
	return 0;
}