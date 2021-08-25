#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=505+5;
int du[max_n];
int dudu[max_n];

int vis[max_n][max_n];
int visvis[max_n][max_n];
// vector<list<int> > vis(505);
// 
// 
// void init()
// {
	// for(int i=1;i<=;i++){
// 		
	// }
// }

bool check(int n,int mid)
{
	queue<pair<int,int> > q;
	// memset(visvis,0,sizeof(visvis));
	// memset(dudu,0,sizeof(dudu));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			visvis[i][j]=vis[i][j];
		}
	}
	for(int i=1;i<=n;i++) dudu[i]=du[i];
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!visvis[i][j]&&dudu[i]+dudu[j]>=mid){
				q.push(make_pair(i,j));
				visvis[i][j]=visvis[j][i]=1;
			}
		}
	}
	
	while(q.size()){
		
		pair<int,int> p=q.front();
		q.pop();
		int f=p.first;
		int s=p.second;
		dudu[f]++;
		dudu[s]++;
		for(int i=1;i<=n;i++){
			if(!visvis[f][i]&&dudu[f]+dudu[i]>=mid){
				q.push(make_pair(f,i));
				visvis[f][i]=visvis[i][f]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(!visvis[s][i]&&dudu[s]+dudu[i]>=mid){
				q.push(make_pair(s,i));
				visvis[i][s]=visvis[s][i]=1;
			}
		}
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!visvis[i][j]) flag=false;
		}
	}
	return flag;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		vis[a][b]=1;
		vis[b][a]=1;
		du[a]++;
		du[b]++;
	}
	for(int i=1;i<=n;i++){
		vis[i][i]=1;
	}
	//init(n);
	int l=0,r=1000,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(n,mid)){
			res=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<res<<endl;
	return 0;
}