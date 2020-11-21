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
char s[105];
int sum1[105],sum0[105];
int sum11[105],sum00[105];
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
		cin>>(s+1);
		sum1[0]=sum0[0]=0;
		sum11[n+1]=sum00[n+1]=0;
		for(int i=1;i<=n;i++){
			sum1[i]=sum1[i-1]+(s[i]=='1');
			sum0[i]=sum0[i-1]+(s[i]=='0');
		}
		for(int i=n;i>=1;i--){
			sum11[i]=sum11[i+1]+(s[i]=='1');
			sum00[i]=sum00[i+1]+(s[i]=='0');
		}
		while(m--){
			int a,b;
			cin>>a>>b;
			bool flag=false;
			if(s[a]=='0'){
				if(sum0[a-1]) flag=true;
			}else{
				if(sum1[a-1]) flag=true;
			}
			if(s[b]=='0'){
				if(sum00[b+1]) flag=true;
			}else{
				if(sum11[b+1]) flag=true;
			}
			if(flag) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}