#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int book[5][5];
int xxx;
int sta[8][2]={
	1,0,
	-1,0,
	1,1,
	-1,-1,
	0,-1,
	0,1,
	1,-1,
	-1,1
};
bool judge(int x,int y){
	return x>=1&&x<=4&&y>=1&&y<=4;
}
bool ok(int x,int y,int xx,int yy,int xxx,int yyy){
	return judge(x,y)&&judge(xx,yy)&&judge(xxx,yyy)&&book[x][y]==book[xx][yy]&&book[xxx][yyy]==book[x][y];
}
int ans=0;
int a,b;
void pri()
{
	cout<<123<<endl;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cout<<(book[i][j]);
		}
		cout<<endl;
	}
}
bool check(int x,int y)
{
	for(int i=0;i<8;i++){
		if(ok(x,y,x+sta[i][0],y+sta[i][1],x+sta[i][0]*2,y+sta[i][1]*2)){
			if(book[x][y]==0) continue;
			return true;
		}
	}
	if(ok(x,y,x-1,y,x+1,y)){
		return true;
	}
	if(ok(x,y,x,y-1,x,y+1)){
		return true;
		
	}
	if(ok(x,y,x-1,y-1,x+1,y+1)){
		return true;
		
	}
	if(ok(x,y,x-1,y+1,x+1,y-1)){
		return true;
	}
	return false;
}
int hi[5];
set<int> vis;
int pow3[3][18];
void dfs(int val,int x,int y,bool flag)
{
	//if(x==4&&y==1&&book[x][y]&&cnt1==cnt2)pri();
	// if(x==4&&y==3){
		// for(int i=1;i<=4;i++) cout<<hi[i]<<endl;
		// pri();
		// cout<<check(x,y)<<endl;
	// }
	if(check(x,y)){
		if(flag&&x==a&&y==b){
			if(!vis.count(val)) ans++,vis.insert(val);
		}
		return ;
	}
	
	for(int i=1;i<=4;i++){
		if(hi[i]==4){
			continue;
		}
		hi[i]++;
		book[hi[i]][i]=flag?1:2;
		dfs(val+pow3[book[hi[i]][i]][(hi[i]-1)*4+i-1],hi[i],i,!flag);
		book[hi[i]][i]=0;
		hi[i]--;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	cin>>x>>a>>b;
	pow3[1][0]=1;
	pow3[2][0]=2;
	for(int i=1;i<=15;i++){
		pow3[1][i]=pow3[1][i-1]*3;
		pow3[2][i]=pow3[1][i]*2;
	}
	xxx=x;
	hi[x]=1;
	book[1][x]=1;
	//book[a][b]=2;
	if(a==1&&b==x){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=4;i++) book[0][i]=1;
	dfs(pow3[1][x-1],1,x,0);
	cout<<ans<<endl;
	return 0;
}