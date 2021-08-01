// Problem: D. Integers Have Friends
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
namespace io{
	const int MAX_SIZE=1<<20;
	char buf[MAX_SIZE],*p1,*p2;
	#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,MAX_SIZE,stdin),p1==p2))?EOF:*p1++)
	inline ll read()
	{
		ll x=0;char ch=gc();
		while (!isdigit(ch))ch=gc();
		while (isdigit(ch)){x=x*10+(ch^48);ch=gc();}
		return x;
	}
}
ll st1[max_n][17];
int log_2[max_n],pow_round[max_n];
void init(int n)
{
	int i,j;
	int ind;
	for(i=1,j=1;(1<<i)<=n;i++,j<<=1){
		for(ind=1;ind<=n&&ind+j<=n;ind++){
			st1[ind][i]=__gcd(st1[ind][i-1],st1[ind+j][i-1]);
		}
	}
	return ;
}
inline ll query(int l,int r)
{
	int len=r-l+1;
	int k=log_2[len];
	return __gcd(st1[l][k],st1[r-pow_round[len]+1][k]);
}
int main()
{
	log_2[0]=-1;
	for(int i=1,j=1;i<=2e5;i++){
		log_2[i]=log_2[i-1];
		pow_round[i]=pow_round[i-1];
		if(i==j) j<<=1,log_2[i]++,pow_round[i]=i; 
	}
	int t;
	t=io::read();
	while(t--){
		int n;
		n=io::read();
		vector<ll> a(n+1);
		for(int i=1;i<=n;i++){
			a[i]=io::read();
		}
		for(int i=2;i<=n;i++){
			st1[i-1][0]=abs(a[i]-a[i-1]);
		}
		init(n-1);
		int ans=1;
		for(int i=1;i<n;i++){
			int l=i,r=n-1;
			int res=-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(query(i,mid)==1){
					r=mid-1;
				}else{
					res=mid;
					l=mid+1;
				}
			}
			ans=max(ans,res-i+2);
		}
		printf("%d\n",ans);
	}
	return 0;
}