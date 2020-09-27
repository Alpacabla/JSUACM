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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		ll sum=0;
		vector<int> num(n);
		bool flag=true,flag1=true;
		for(i=0;i<n;i++){
			cin>>num[i];
			sum+=num[i];
			if(num[i]!=x) flag=false;
			if(num[i]==x) flag1=false;
		}
		if(flag) cout<<0<<endl;
		else {
			if(!flag1){
				cout<<1<<endl;
				continue;
			}
			if(x==0){
				if(sum==0) cout<<1<<endl;
				else cout<<2<<endl;
			}else{
				if(sum%x==0&&sum%n==0&&sum/x==n){
					cout<<1<<endl;
				}else{
					cout<<2<<endl;
				}
			}
		}
	}
	return 0;
}
