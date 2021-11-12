// Problem: E. Freezing with Style
// Contest: Codeforces - Codeforces Round #107 (Div. 1)
// URL: https://codeforces.com/contest/150/problem/E
// Memory Limit: 256 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}

int l,r;
bool vis[max_n];
int siz[max_n];
void calsiz(int a,int pa)
{
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=pa){
			calsiz(u,a);
			siz[a]+=siz[u];
		}
	}
	return ;
}
int minsiz,cen,all;
void calcen(int a,int pa)
{
	int max1=all-siz[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=pa){
			calcen(u,a);
			max1=max(max1,siz[u]);
		}
	}
	if(max1<minsiz){
		cen=a,minsiz=max1;
	}
	return ;
}
int depe[max_n],hei[max_n];
void calhei(int a,int pa)
{
	hei[a]=1;
	depe[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=pa){
			hei[u]=hei[a]+1;
			calhei(u,a);
			depe[a]=max(depe[a],depe[u]+1);
		}
	}
	return ;
}
int col[max_n];
int l1,r1,ans;
int val[max_n];
vector<int> valval;
int v1[max_n],v2[max_n];
void getcol(int a,int pa,int mid_val,int vvv)
{
	col[a]=(val[a]>=mid_val?1:-1);
	vvv+=col[a];
	v2[hei[a]-1]=max(v2[hei[a]-1],vvv);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=pa){
			getcol(u,a,mid_val,vvv);
		}
	}
	return ;
}
bool check(int a,int mid)
{
	bool flag=false;
	int dep=1;
	int z=v1[1]=(val[a]>=valval[mid]?1:-1);
	
	for(int i=head[a];i&&!flag;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			getcol(u,a,valval[mid],0);
			deque<int> q1,q2;
			int dd=dep+1;
			for(int j=l-1;j<=r-1&&j<=dep;j++){
				while(q1.size()&&v1[j]>=q2.back()){
					q1.pop_back();
					q2.pop_back();
				}
				q1.push_back(j);
				q2.push_back(v1[j]);
				dd=j;
			}
			
			int max1=-int_inf;
			for(int j=1;j<=depe[u];j++){
				if(q1.size()){
					max1=max(max1,q2.front()+v2[j]);
				}
				if(q1.size()&&q1.front()+j+1>l){
					q1.pop_front(),q2.pop_front();
				}
				while(dd<dep&&q1.size()&&v1[dd+1]>=q2.back()){
					q1.pop_back();
					q2.pop_back();
				}
				if(dd<dep){
					q1.push_back(dd+1);
					q2.push_back(v1[dd+1]);
					dd++;
				}
			}
			flag=(max1>=0);
			for(int j=1;j<=depe[u];j++){
				v1[j+1]=max(v1[j+1],v2[j]+z);
				v2[j]=-int_inf;
			}
			dep=depe[u]+1;
		}
	}
	for(int j=1;j<=dep;j++) v1[j]=0;
	return flag;
}
void solve(int a)
{
	calhei(a,0);
	vector<int> vv;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			vv.push_back(u);
		}
	}
	sort(vv.begin(),vv.end(),[](int a,int b) -> bool{
		return depe[a]<depe[b];
	});
	int l2=l1,r2=r1,res=-1;
	while(l2<=r2){
		int mid=(l2+r2)>>1;
		if(check(a,mid)){
			res=mid;
			l2=mid+1;
		}else r2=mid-1;
	}
	if(res!=-1){
		ans=res;
		l1=res+1;
	}
	return ;
}
void dfz(int a)
{
	calsiz(a,0);
	minsiz=int_inf;
	all=siz[a];
	calcen(a,0);
	
	solve(cen);
	vis[cen]=true;
	for(int i=head[cen];i;i=nxt[i]){
		if(!vis[to[i]]){
			dfz(to[i]);
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n>>l>>r;
	valval.resize(n+1);
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b>>val[i];
		valval[i]=val[i];
		add(a,b);
		add(b,a);
	}
	sort(valval.begin()+1,valval.end());
	int k=(int)(unique(valval.begin()+1,valval.end())-valval.begin());
	cout<<k<<endl; 
	l1=1,r1=k;
	dfz(1);
	cout<<ans<<endl;
	return 0;
}