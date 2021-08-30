// Problem: E. Equilibrium
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;

ll st1[max_n][17],st2[max_n][17];
int log_2[max_n],pow_round[max_n];

void init(int n,ll st1[max_n][17])
{
	int i,j;
	int ind;
	log_2[0]=-1;
	for(i=1,j=1;i<=n;i++){
		log_2[i]=log_2[i-1];
		pow_round[i]=pow_round[i-1];
		if(i==j) j<<=1,log_2[i]++,pow_round[i]=i; 
	}
	for(i=1,j=1;(1<<i)<=n;i++,j<<=1){
		for(ind=1;ind<=n&&ind+j<=n;ind++){
			st1[ind][i]=max(st1[ind][i-1],st1[ind+j][i-1]);
		}
	}
	return ;
}
inline ll query(int l,int r,ll st1[max_n][17])
{
	int len=r-l+1;
	int k=log_2[len];
	return max(st1[l][k],st1[r-pow_round[len]+1][k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	vector<ll> sum(n+1),d(n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i]-b[i];
		st2[i][0]=sum[i];
		st1[i][0]=-(sum[i]);
	}
	init(n,st1);
	init(n,st2);
	while(q--){
		int l,r;
		cin>>l>>r;
		if(sum[r]-sum[l-1]!=0||(query(l,r,st2)-sum[l-1])>0){
			cout<<-1<<endl;
		}else{
			cout<<query(l,r,st1)+sum[l-1]<<endl;
		}
	}
	return 0;
}