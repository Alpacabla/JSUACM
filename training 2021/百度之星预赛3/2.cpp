/*
link: 
tags: 
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
const int max_n=1e5+5;
char book[15][15];
bool vis[15][15];
int ans=0;
bool flag;
int sta[2][2]={
	1,0,
	0,1
};
// struct cmp{
//     bool operator() (vector<int> a,vector<int> b){
//     	for(int i=0;i<a.size();i++){
//     		if(a[i]==b[i]) return false;
//     	}
//     	return a<b;
//     }
// };
//set<vector<int> ,cmp> sets;
vector<vector<int> >vv;
int n;
bool judge(int a,int b)
{
	if(a<0||a>=n||b<0||b>=n) return true;
	else return false;
}
int aa[15];
// bool down(vector<int> &v,vector<vecotr<int> > &vv)
// {
// 	for(int i=0;i<vv.size();i++){
// 		bool flag=true;
// 		for(int j=0;j<v.size()&&flag;j++){
// 			if(v[j]==vv[i][j]) flag=false;
// 		}
// 		if(flag) return true;
// 	}
// 	return false;
// }
void dfs(int a,int b,int step)
{
	if(flag) return ;
	if(judge(a,b)||book[a][b]!='.') return ;
	vis[a][b]=true;
	aa[step]=a*n+b;
	if(a==n-1&&b==n-1){
		if(ans==0) ans=1;
		vector<int> v;
		for(int i=1;i<step;i++){
			v.push_back(aa[i]);
		}
		bool res=false;
		for(int i=0;i<vv.size()&&!res;i++){
			bool flag1=true;
			for(int j=0;j<v.size()&&flag1;j++){
				if(v[j]==vv[i][j]) flag1=false;
			}
			if(flag1) res=true;
		}
		if(res){
			ans=2;
			flag=true;
		}else{
			vv.push_back(v);
		}
		return ;
	}
	for(int i=0;i<2;i++){
		int x=a+sta[i][0],y=b+sta[i][1];
		dfs(x,y,step+1);
		if(flag) return ;
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",book[i]);
		}
		if(book[0][0]=='#'||book[n-1][n-1]=='#'){
        	printf("0\n");
        	continue;
        }
        if(n==1){
        	printf("1\n");
        	continue;
        }
        vv.clear();
        // vector<vector<int>> s;
        // vv.swap(s);
        // set<vector<int>,cmp> s;
        // sets.swap(s);
        //sets.clear();
		ans=0;
		flag=false;
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}