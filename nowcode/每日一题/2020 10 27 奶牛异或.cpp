/*
link: http://jsuacm.cn/problem.php?cid=1578&pid=19
	  https://ac.nowcoder.com/acm/problem/22998
tags: 01trie模板题
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
ll sum[max_n];
int trie[max_n*40][2];
void insert(ll val)
{
	int now=0;
	static int tot=0;
	for(int i=31;i>=0;i--){
		int k=(val>>i)&1;
		now=(trie[now][k]?trie[now][k]:(trie[now][k]=++tot));
	}
	return ;
}
int check(ll val)
{
	ll res=0;
	int now=0;
	for(int i=31;i>=0;i--){
		int k=(val>>i)&1^1;
		if(trie[now][k]) now=trie[now][k],res+=(1<<i);
		else now=trie[now][!k];
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		sum[i]=sum[i-1]^a;
	}
	int ans=-1;
	int end=1,start=1;
	insert(0);
	for(int i=1;i<=n;i++){
		int chk=check(sum[i]);
		if(ans<chk){
			ans=chk;
			end=i;
		}
		insert(sum[i]);
	}
	for(int i=0;i<end;i++){
		if((sum[end]^sum[i])==ans){
			start=i+1;
		}
	}
	cout<<ans<<" "<<start<<" "<<end<<endl;
	return 0;
}