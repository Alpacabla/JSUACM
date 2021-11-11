// Problem: F. 地图压缩
// Contest: Codeforces - 2021年中国大学生程序设计竞赛女生专场
// URL: https://codeforces.com/gym/103389/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
string s[2005];
const int mod=1e9+7;
ll base=29;
int hash1[2005][2005],hash2[2005][2005];
int xx[2005];
int get_val(int hash[2005][2005],int x,int l,int r){
	return ((hash[x][r]-(hash[x][l-1]*(1ll*xx[r-l+1])%mod))%mod+mod)%mod;
}
int get_nxt(vector<int> &nxt,int hash[2005][2005],int x1,int x2,int l,int r)
{
	int n=x2-x1+1;
	nxt[0]=-1;
	nxt[1]=0;
	for(int i=1;i<n;i++){
		int j=i;
		while(j!=0&&get_val(hash,i+x1,l,r)!=get_val(hash,nxt[j]+x1,l,r)) j=nxt[j];
		nxt[i+1]=nxt[j]+1;
		// while(j!=0&&s[i+x1]!=s[nxt[j]+x1]) j=nxt[j]; 
		// nxt[i+1]=nxt[j]+1;
	}
	return n-nxt[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	xx[0]=1;
	for(int i=1;i<=n;i++){
		xx[i]=xx[i-1]*base%mod;
		for(int j=1;j<=n;j++){
			hash1[i][j]=(hash1[i][j-1]*base+(s[i][j]-'a'+1))%mod;
			hash2[j][i]=(hash2[j][i-1]*base+(s[i][j]-'a'+1))%mod;
		}
	}
	vector<int> nxt(n+1);
	while(m--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int d=get_nxt(nxt,hash1,x1,x2,y1,y2),w=get_nxt(nxt,hash2,y1,y2,x1,x2);
		//cout<<d<<" "<<w<<endl;
		cout<<d*w<<endl;
	}
	
	return 0;
}