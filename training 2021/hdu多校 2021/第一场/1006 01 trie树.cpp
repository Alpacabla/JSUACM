/*
link: https://acm.hdu.edu.cn/showproblem.php?pid=6955
tags: 01字典树，维护一下最靠右的位置，然后多利用前缀的思想处理，
	  分成相等和大于两种情况讨论
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
const int max_n=4e6+5;
int trie[max_n][2],pos[max_n][2];
int tot;
#define zzz ((a>>i)&1)
void ins(int a,int r)
{
	int now=0;
	for(int i=30;i>=0;i--){
		if(trie[now][zzz]){
			if(pos[now][zzz]<r) pos[now][zzz]=r;
			now=trie[now][zzz];
		}else{
			trie[now][zzz]=++tot;
			pos[now][zzz]=r;
			now=tot;
		}
	}
	return ;
}
int check(int a,int k)
{
	int res=-int_inf;
	int now=0;
	int last=-int_inf;
	for(int i=30;i>=0;i--){
		if(((k>>i)&1)==0&&trie[now][zzz^1]){
			res=max(res,pos[now][zzz^1]);
		}
		if(trie[now][zzz]){
			last=pos[now][zzz];
			now=trie[now][zzz];
		}else{
			return res;
		}
	}
	return max(res,last);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		memset(trie,0,sizeof(int)*(tot+3)*(2));
		memset(pos,0,sizeof(int)*(tot+3)*(2));
		tot=0;
		int last=0;
		ins(last,0);
		int max1=int_inf;
		int l,r;
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			last^=a;
			int l1=check(last^k,k);
			if(i-l1<max1){
				max1=i-l1;
				l=l1+1;
				r=i;
			}
			ins(last,i);
		}
		if(max1==int_inf){
			printf("-1\n");
		}else{
			printf("%d %d\n",l,r);
		}
	}
	return 0;
}