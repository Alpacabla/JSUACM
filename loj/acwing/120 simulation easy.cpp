/*
link: https://www.acwing.com/problem/content/120/
tags: simulation easy
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
char book[3000][3000];
int xx[10];
void init(const int n)
{
	int i,j,k;
	int x;
	xx[1]=x=1;
	book[1][1]='X';
	for(i=1;i<n;i++){
		int t1,t2;
		for(j=1,t1=1;t1<=x;j++,t1++){
			for(k=x+x+1,t2=1;t2<=x;k++,t2++){
				book[j][k]=book[t1][t2];
			}
		}
		for(j=x+1,t1=1;t1<=x;j++,t1++){
			for(k=x+1,t2=1;t2<=x;k++,t2++){
				book[j][k]=book[t1][t2];
			}
		}
		for(j=x+x+1,t1=1;t1<=x;j++,t1++){
			for(k=1,t2=1;t2<=x;k++,t2++){
				book[j][k]=book[t1][t2];
			}
		}
		for(j=x+x+1,t1=1;t1<=x;j++,t1++){
			for(k=x+x+1,t2=1;t2<=x;k++,t2++){
				book[j][k]=book[t1][t2];
			}
		}
		x=j-1;
		xx[i+1]=x;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	init(7);
	while(cin>>n){
		if(n==-1){
			break;
		}
		for(i=1;i<=xx[n];i++){
			for(j=1;j<=xx[n];j++){
				cout<<(!book[i][j]?' ':book[i][j]);
			}
			cout<<endl;
		}
		cout<<'-'<<endl;
		//cin>>
	}
	return 0;
}
