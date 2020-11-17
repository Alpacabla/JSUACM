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
		int n,c1,c2,h;
		string s;
		cin>>n>>c1>>c2>>h;
		int ans=int_inf;
		int a1=0,a2=0;
		cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='0') a1++;
			else a2++;
		}
		for(int i=0;i<=n;i++){
			int now=0;
			now+=(abs(a1-i)*h)+c1*i+c2*(n-i);
			ans=min(ans,now);
		}
		cout<<ans<<endl;
	}
	return 0;
}