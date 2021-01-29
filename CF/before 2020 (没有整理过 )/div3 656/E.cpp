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
int head[max_n],nxt[max_n],to[max_n],cnt=1;
inline void add(int a,int b){
	nxt[++cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
	return ;
}
int in[max_n],dag[max_n],now;
int sta[max_n];
void DAG(int n)
{
	int end=0;
	for(int i=1;i<=n;i++){
		if(!in[i]) sta[++end]=i;
	}
	while(end){
		const int a=sta[end--];
		dag[a]=++now;
		for(int i=head[a];i;i=nxt[i]){
			in[to[i]]--;
			if(!in[to[i]]){
				sta[++end]=to[i];
			}
		}
	}
	return ;
}
int main()
{
	int i,j;
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		vector<pair<int,int> > undirs;
		undirs.clear();
		memset(in,0,(n+3)*sizeof(int));
		memset(head,0,(n+3)*sizeof(int));
		cnt=1;
		for(i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&c,&a,&b);
			if(c) add(a,b),in[b]++;
			undirs.push_back(make_pair(a,b));
		}
		now=0;
		DAG(n);
		if(now!=n) printf("NO\n");
		else{
			printf("YES\n");
			for(i=0;i<undirs.size();i++){
				if(dag[undirs[i].first]<dag[undirs[i].second]) printf("%d %d\n",undirs[i].first,undirs[i].second);
				else printf("%d %d\n",undirs[i].second,undirs[i].first);
			}
		}
	}
	return 0;
}