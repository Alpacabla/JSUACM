#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e4+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
double pk[max_n],pe[max_n];
int du[max_n];

vector<double> dfs(int a,int fa)
{
	int &cnt=du[a];
	vector<double> res={pk[a],(1.0-pk[a]-pe[a])/cnt,1-pk[a]-pe[a]};
	double f=1;
	vector<double> sum(3,0);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			vector<double> k=dfs(u,a);
			for(int j=0;j<3;j++) sum[j]+=k[j]*res[1];
		}
	}
	if(!cnt){
		
	}else{
		res[0]+=sum[0];
		res[2]+=sum[2];
		for(int i=0;i<3;i++){
			res[i]/=(1-sum[1]);
		}
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	int gg=0;
	while(t--){
		int n;
		cin>>n;
		tot=1;
		for(int i=1;i<=n;i++) head[i]=0,du[i]=0;
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
			du[a]++;
			du[b]++;
		}
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",pk+i,pe+i);
			pk[i]/=100;
			pe[i]/=100;
		}
		vector<double> res=dfs(1,0);
		printf("Case %d: ",++gg);
		if(fabs(1-res[0])<=1e-9) printf("impossible\n");
		else printf("%.6lf\n",res[2]/(1-(res[0])));
	}
	return 0;
}