// Problem: D. Playoff Tournament
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/D
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
const int max_n=262160;
int cnt[max_n<<2];
char vv[max_n<<2];
void maintain(int ind,int l,int r){
	switch(vv[ind]){
		case '0':
			cnt[ind]=cnt[to_l(ind)];
			break;
		case '1':
			cnt[ind]=cnt[to_r(ind)];
			break;
		case '?':
			cnt[ind]=cnt[to_r(ind)]+cnt[to_l(ind)];
			break;
	}
	return ;
}
void change(int l1,int r1,int l,int r,int ind,char val)
{
	if(l>r1||r<l1) return ;
	if(l>=l1&&r<=r1){
		vv[ind]=val;
		maintain(ind,l,r);
		return ;
	}
	int mid=(1ll*l+r)>>1;
	change(l1,r1,l,mid,to_l(ind),val);
	change(l1,r1,mid+1,r,to_r(ind),val);
	maintain(ind,l,r);
	return ;
}
int iil[max_n],iir[max_n];
int cntcnt[max_n];
int tot=0;
string s;
void build_tree(int l,int r,int ind,int x)
{
	if(l==r){
		cnt[ind]=1;
		return ;
	}
	int mid=(1ll*l+r)>>1;
	build_tree(l,mid,to_l(ind),x>>1);
	build_tree(mid+1,r,to_r(ind),x>>1);
	vv[ind]=s[tot++];
	iil[++cntcnt[x]]=l;
	iir[cntcnt[x]]=r;
	maintain(ind,l,r);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin>>k;
	int lim=(1<<(k));
	for(int i=0;i<=lim;i++){
		cntcnt[i]=i;
	}
	cin>>s;
	build_tree(1,lim,1,lim);
	int m;
	cin>>m;
	while(m--){
		int p;
		char c;
		cin>>p>>c;
		if(p==5){
			cout<<p<<endl;
			cout<<iil[p]<<" "<<iir[p]<<endl;
		}
		change(iil[p],iir[p],1,lim,1,c);
		cout<<cnt[1]<<endl;
	}
	return 0;
}