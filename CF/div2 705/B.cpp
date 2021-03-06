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
int n,m;
int to[10];
bool vis[10];
struct node{
	int a,b;
	inline void add(){
		b++;
		if(b>=m){
			a++;
			b=0;
		}
		if(a>=n){
			a=0;
		}
		return ;
	}

	bool check(){
		int t[4];
		int num[4];
		t[0]=a/10%10;
		t[1]=a%10;
		t[2]=b/10%10;
		t[3]=b%10;
		for(int i=0;i<4;i++){
			if(!vis[t[i]]){
				return false;
			}
			//t[i]=to[t[i]];
		}
		for(int i=0;i<4;i++){
			num[i]=to[t[4-i-1]];
		}
		int aa=num[0]*10+num[1],bb=num[2]*10+num[3];
		if(aa>=n||bb>=m) return false; 
		else{
			
			return true;
		}
	}
	void pri(){
		int t[4];
		t[0]=a/10%10;
		t[1]=a%10;
		t[2]=b/10%10;
		t[3]=b%10;
		printf("%d%d:%d%d\n",t[0],t[1],t[2],t[3]);
		return ;
	}
};
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int i,j;
	int t;
	vis[0]=vis[1]=vis[2]=vis[5]=vis[8]=true;
	to[0]=0;
	to[1]=1;
	to[8]=8;
	to[2]=5;
	to[5]=2;
	cin>>t;
	while(t--){
		//int n,m;
		//cin>>n>>m;
		int nowa,nowb;
		scanf("%d%d",&n,&m);
		int lim=n*m+100;
		scanf("%d:%d",&nowa,&nowb);
		int min1=int_inf;
		node t;
		t.a=nowa;
		t.b=nowb;
		node ans;
		if(t.check()){
			ans=t;
			ans.pri();
			continue;
		}
		for(int i=1;i<=lim;i++){
			t.add();
			if(t.check()){
				ans=t;
				min1=i;
				break;
			}
		}
		// t.a=nowa;
		// t.b=nowb;
		// for(int i=1;i<=lim;i++){
		// 	t.del();
		// 	if(t.check()){
		// 		if(i<min1){
		// 			ans=t;
		// 		}
		// 		break;
		// 	}
		// }
		ans.pri();
	}
	return 0;
}