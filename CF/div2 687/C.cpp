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
		int n,p,k,x,y;
		cin>>n>>p>>k;
		string s;
		cin>>s;
		vector<int> num(2*(n+1));
		cin>>x>>y;
		for(int i=n;i>=1;i--){
			num[i]=num[i+k]+(s[i-1]=='0');
		}
		int ans=int_inf;
		int now=0;
		for(int i=p;i<=n;i++){
			ans=min(ans,now+num[i]*x);
			now+=y;
		}
		cout<<ans<<endl;
	}
	return 0;
}