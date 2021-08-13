/*
link: https://acm.hdu.edu.cn/showproblem.php?pid=7064
tags: 不要忘记了trie树的多模式匹配能力
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
const int max_n=4e5+5;
const int max_m=1e5+5;
int trie[max_n][26];
int last[max_n],cnt[max_n];
vector<int> ind[max_n];
char s[max_m];
int ans[max_m];
int tot;
void insert(char *s,int iii)
{
	int now=0;
	for(int i=0;s[i];i++){
		if(trie[now][s[i]-'a']){
			now=trie[now][s[i]-'a'];
		}else{
			trie[now][s[i]-'a']=++tot;
			now=tot;
		}
	}
	ind[now].emplace_back(iii);
	return ;
}
void init()
{
	// for(int i=0;i<=tot;i++){
	// 	ind[i].clear();
	// }
	// memset(last,-1,sizeof(int)*(tot+2));
	// memset(cnt,0,sizeof(int)*(tot+2));
	memset(trie,0,sizeof(int)*(tot+2)*(26));
	tot=0;
}
void check(char *s,int iii)
{
	int now=0;
	int i=0;
	for(i=0;s[i];i++){
		if(trie[now][s[i]-'a']){
			now=trie[now][s[i]-'a'];
			if(ind[now].size()){
				if(last[now]<iii){
					cnt[now]++;
					last[now]=iii+i;
				}
			}
		}else{
			break;
		}
	}
	if(ind[now].size()){
		if(last[now]<iii){
			cnt[now]++;
			last[now]=iii+i;
		}
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%s",s);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			char ss[35];
			scanf("%s",ss);
			insert(ss,i);
		}
		for(int i=0;s[i];i++){
			check(s+i,i+1);
		}
		for(int i=0;i<=tot;i++){
			if(ind[i].size()){
				for(int j=0;j<ind[i].size();j++){
					ans[ind[i][j]]=cnt[i];
				}
				ind[i].clear();
				cnt[i]=0;
				last[i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}