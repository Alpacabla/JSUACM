/*
link: https://ac.nowcoder.com/acm/contest/11253/L
tags: 分块思想，算好复杂度很重要，不同于传统分块，是对点分为大点和小点。
	  然后就是要注意很多细节。
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
const int max_n=1e6+5,max_m=1e4+5;
const int sqn=650;
int last[max_n],steps[max_n];
bool sta[max_n];
int du[max_n],bg[max_n];
int ans[max_n];
vector<int> chp[sqn+5][max_m],bigbig[sqn+5];
int lim[max_n];
int big[max_n],tot;

int head[max_n],to[max_n<<1],nxt[max_n<<1];
inline void add(int a,int b){
	static int tot=1;
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
void init(int n)
{
	for(int i=1;i<=n;i++){
		if(du[i]>=sqn){
			big[i]=++tot;
			bg[tot]=i;
		}
	}
	for(int i=1;i<=tot;i++){
		for(int j=head[bg[i]];j;j=nxt[j]){
			int &u=to[j];
			if(big[u]){
				bigbig[i].push_back(u);
			}
		}
	}
	return ;
}
inline void lose(int a,int t){
	sta[a]=false;
	ans[a]+=t-last[a];
	return ;
}
inline void win(int a,int t){
	sta[a]=true;
	last[a]=t;
	return ;
}
int main()
{
	int n,m,q;
	tot=0;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		du[a]++;
		du[b]++;
	}
	init(n);
	for(int qq=1;qq<=q;qq++){
		int a,w;
		scanf("%d%d",&a,&w);
		if(big[a]){
			int &ind=big[a];
			for(int i=steps[a]+1;i<=steps[a]+w;i++){
				for(int j=0;j<chp[ind][i].size();j++){
					int &u=chp[ind][i][j];
					if(sta[u]&&steps[a]+w>=steps[u]){
						lose(u,qq);
					}
				}
			}
			steps[a]+=w;
			// for(int j=0;j<chp[ind][steps[a]].size();j++){
			// 	int &u=chp[ind][steps[a]][j];
			// 	if(sta[u]&&steps[a]>=steps[u]) lose(u,qq);
			// }
			for(int i=0;i<bigbig[ind].size();i++){
				int &u=bigbig[ind][i];
				int &indind=big[u];
				lim[u]=max(lim[u],steps[a]);
				if(steps[a]>=steps[u]){
					if(sta[u]) lose(u,qq);
					//lim[indind]=max(lim[indind],steps[a]);
					//cnt[indind]++;
					chp[indind][steps[a]].push_back(a);
				}
			}
			if(!sta[a]&&steps[a]>lim[a]){
				win(a,qq);
			}
		}else{
			steps[a]+=w;
			// if(sta[a]){
			// 	for(int i=head[a];i;i=nxt[i]){
			// 		int &u=to[i];
			// 		if(steps[a]>=steps[u]){
			// 			if(sta[u]) lose(u,qq);
			// 			if(big[u]){
			// 				int &ind=big[u];
			// 				cnt[ind]++;
			// 				chp[ind][steps[a]].push_back(a);
			// 			}
			// 		}
			// 	}
			// }else{
				bool flag=true;
				for(int i=head[a];i;i=nxt[i]){
					int &u=to[i];
					lim[u]=max(lim[u],steps[a]);
					if(steps[a]>=steps[u]){
						if(sta[u]) lose(u,qq);
					}
					if(steps[a]<=steps[u]) flag=false;
				}
				if(flag){
					for(int i=head[a];i;i=nxt[i]){
						int &u=to[i];
						if(big[u]){
							int &ind=big[u];
							//cnt[ind]++;
							//lim[ind]=max(lim[ind],steps[a]);
							chp[ind][steps[a]].push_back(a);
						}
					}
				}
				if(flag&&!sta[a]){
					win(a,qq);
				}
			//}
		}
	}
	for(int i=1;i<=n;i++){
		if(sta[i]){
			lose(i,q);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}