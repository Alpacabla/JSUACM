// Problem: E. Oolimry and Suffix Array
// Contest: Codeforces - Codeforces Round #723 (Div. 2)
// URL: https://codeforces.com/contest/1526/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int mod=998244353;
ll qpow(ll a,int b)
{
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll x[max_n],inv_x[max_n];
void init(int n)
{
	x[0]=1;
	inv_x[0]=1;
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]*i%mod;
		inv_x[i]=qpow(x[i],mod-2);
	}
	return ;
}
ll C(int a,int b){
	if(a<b) return 0;
	return x[a]*inv_x[b]%mod*(inv_x[a-b])%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(2e5);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1),pos(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	int cnt=0;
	for(int i=1;i<n;i++){
		if(/*a[i]+1<=n&&a[i+1]+1<=n&&*/pos[a[i]+1]>pos[a[i+1]+1]) cnt++;
	}
	cout<<cnt<<endl;
	cout<<(n-(cnt+1))<<endl;
	cout<<C(k,cnt+1)*C(n-(cnt+1)+n-1,n-1)%mod<<endl;
	return 0;
}