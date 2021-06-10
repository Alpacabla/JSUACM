/*
link: 
tags: 现场没做出来的题，太可惜了，orz
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
#define endl '\n'
int max1[max_n<<2],add[max_n<<2];
void push_down(int ind){
	if(add[ind]){
		add[to_l(ind)]+=add[ind];
		add[to_r(ind)]+=add[ind];
		max1[to_l(ind)]+=add[ind];
		max1[to_r(ind)]+=add[ind];
		add[ind]=0;
	}
	return ;
}
void maintain(int ind){
	max1[ind]=max(max1[to_l(ind)],max1[to_r(ind)]);
	return ;
}

void change(int l,int r,int l1,int r1,int ind,int val)
{
	if(l1>r||r1<l) return ;
	if(l1>=l&&r1<=r){
		add[ind]+=val;
		max1[ind]+=val;
		return ;
	}
	push_down(ind);
	int mid=(l1*1ll+r1)>>1;
	change(l,r,l1,mid,to_l(ind),val);
	change(l,r,mid+1,r1,to_r(ind),val);
	maintain(ind);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1),dp(n+1),dpnow(n+1),last(n+1),vis(n+1),cnt(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt[a[i]]++;
			if(vis[a[i]]){
				if(cnt[a[i]]==2) dpnow[i]=dpnow[i-1]-1;
				else dpnow[i]=dpnow[i-1];
			}else{
				dpnow[i]=dpnow[i-1]+1;
			}
			last[i]=vis[a[i]];
			vis[a[i]]=i;
		}
		for(int i=2;i<=m;i++){
			memset(max1,0,sizeof(int)*(n<<2)+3);
			memset(add,0,sizeof(int)*(n<<2)+3);
			for(int j=1;j<=n;j++){
				dp[j]=dpnow[j];
			}
			for(int j=1;j<i;j++){
				change(j,j,1,n,1,dp[j]);
			}
			for(int j=i;j<=n;j++){
				int l,r;
				l=last[j];r=j-1;
				change(l,r,1,n,1,1);
				l=last[last[j]];r=last[j]-1;
				if(l<=r){
					change(l,r,1,n,1,-1);
				}
				dpnow[j]=max1[1];
				change(j,j,1,n,1,dp[j]);
			}
		}
		cout<<dpnow[n]<<endl;
	}
	return 0;
}

/*
4
2 2
1 1
3 2
1 1 1
4 2 
1 2 2 1
6 3 
1 1 2 2 3 3
*/