#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2020;
struct nodes{
	int cnt,v;
	bool operator < (const nodes &a) const {
		return v>a.v;
	}
};
set<nodes>num_set[200];
int v[200];
int vis[2020][2020];
int ans[2020];
int in[2020];
const int lim=(1<<7)-1;
void init()
{
	string s[10]={ "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	int i,j;
	for(i=0;i<=lim;i++) v[i]=-1;
	for(i=0;i<=9;i++){
		int k=0,x=1;
		for(j=6;j>=0;j--){
			k+=(s[i][j]=='1')*x;
			x<<=1;
		}
		v[k]=i;
	}
}
inline int get_bit(int t)
{
	int cnt=0;
	while(t) cnt+=(t&1),t>>=1;
	return cnt;
}
void get_v(int t)
{
	int i;
	for(i=0;i<=lim;i++){
		if((i&t)==0&&v[i+t]!=-1){
			num_set[t].insert((nodes){get_bit(i),v[i+t]});
		}
	}
	return ;
}
int n,m;
void pri()
{
	int i;
	for(i=1;i<=n;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return ;
}
void dfs(int a,int len)
{
	if(vis[a][len]) return ;
	if(len>m) return ;
	if(a>n){
		if(len!=m){ 
			return ;
		}
		pri();
		exit(0);
	}
	vis[a][len]=1;
	int i;
	for(set<nodes>::iterator it=num_set[in[a]].begin();it!=num_set[in[a]].end();it++){
		nodes t=*it;
		ans[a]=t.v;
		dfs(a+1,len+t.cnt);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	init();
	get_v(73);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>in[i];
		int k=0,x=1;
		while(in[i]){
			k+=(in[i]&1)*x;
			x<<=1;
			in[i]/=10;
		}
		in[i]=k;
		if(!num_set[in[i]].size()){
			get_v(in[i]);
		}
	}
	dfs(1,0);
	cout<<"-1"<<endl;
	return 0;
}