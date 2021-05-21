// Problem: E. Partition Game
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int max_n=3.5e4+5;
int max1[max_n<<2],add1[max_n<<2];
inline void maintain(int *max1,int *add1,int ind,int l,int r)
{
	max1[ind]=min(max1[to_l(ind)],max1[to_r(ind)]);
	max1[ind]+=add1[ind];
	return ;
}
void add(int *max1,int *add1,int v,int ind,int l,int r,int l1,int r1)
{
	if(l1>r||r1<l) return ;
	if(l1>=l&&r1<=r){
		add1[ind]+=v;
		max1[ind]+=v;
		return ;
	}
	int mid=(l1+r1)>>1;
	add(max1,add1,v,to_l(ind),l,r,l1,mid);
	add(max1,add1,v,to_r(ind),l,r,mid+1,r1);
	maintain(max1,add1,ind,l,r);
	return ;
}
int query(int *max1,int *add1,int ind,int l,int r,int l1,int r1,int res=0)
{
	if(l1>r||r1<l) return int_inf;
	if(l1>=l&&r1<=r){
		return res+max1[ind];
	}
	res+=add1[ind];
	int mid=(l1+r1)>>1;
	return min(query(max1,add1,to_l(ind),l,r,l1,mid,res),
	query(max1,add1,to_r(ind),l,r,mid+1,r1,res));
}
int last[max_n];
int dp[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(last[a[i]]==0) last[a[i]]=i;
		sum+=i-last[a[i]];
		dp[i]=sum;
		last[a[i]]=i;
	}
	
	for(int j=2;j<=k;j++){
		memset(max1,0,sizeof(max1));
		memset(add1,0,sizeof(add1));
		memset(last,0,sizeof(last));
		for(int i=1;i<j;i++) last[a[i]]=i;
		for(int i=j;i<=n;i++){
			if(last[a[i]]==0){
				last[a[i]]=i;
			}
			add(max1,add1,i-last[a[i]],1,1,(last[a[i]]-1==0?1:last[a[i]]-1),1,n);
			int k=query(max1,add1,1,1,(i-1==0?1:i-1),1,n);
			add(max1,add1,dp[i],1,i,i,1,n);
			dp[i]=k;
			last[a[i]]=i;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}