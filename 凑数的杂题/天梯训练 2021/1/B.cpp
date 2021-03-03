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
bool vis1[10],vis2[20],vis3[20];
int t[10];
vector<int> a;
int tot=0;
void dfs(int x)
{
	if(x==9){
		a.resize(a.size()+8);
		for(int i=1;i<=8;i++){
			a[tot++]=t[i];
		}
		return ;
	}
	for(int i=1;i<=8;i++){
		if(!vis1[i]&&!vis2[x+i]&&!vis3[9-x+i]){
			t[x]=i;
			vis1[i]=true;
			vis2[x+i]=true;
			vis3[9-x+i]=true;
			dfs(x+1);
			vis1[i]=false;
			vis2[x+i]=false;
			vis3[9-x+i]=false;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int k;
	dfs(1);
	cin>>k;
	while(k--){
		int num[10][10];
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				cin>>num[i][j];
			}
		}
		int max1=-1;
		for(int i=0;i<tot;i+=8){
			int sum=0;
			for(int j=1;j<=8;j++){
				sum+=num[j][a[j+i-1]];
			}
			max1=max(sum,max1);
		}
		cout<<max1<<endl;
	}
	
	return 0;
}