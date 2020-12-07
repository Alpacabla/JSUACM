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
const int max_n=2e6+5;
int trie[max_n][2];
void ins(int v)
{
	int now=0;
	static int tot=1;
	for(int i=30;i>=0;i--){
		now=trie[now][(v>>i)&1]?trie[now][(v>>i)&1]:(trie[now][(v>>i)&1]=tot++);
	}
	return ;
}
int check(int v)
{
	int now=0;
	int res=0;
	for(int i=30;i>=0;i--){
		int val=!((v>>i)&1);
		if(trie[now][val]) res+=(1<<i),now=trie[now][val];
		else now=trie[now][!val];
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
	vector<int> num(n+1);
	int ans=-1;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		ins(num[i]);
		ans=max(ans,check(num[i]));
	}
	cout<<ans<<endl;
	return 0;
}