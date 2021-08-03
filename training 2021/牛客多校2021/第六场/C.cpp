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
#define endl '\n'
bool vis[2005][2005];
//int cnt[2005];
int main()
{
	int n;
	scanf("%d",&n);
	cout<<(2000*1999)/2-655731*3<<endl;
	vector<int> x,y,z;
	int l1=n/3,l2=2*n/3;
	for(int i=1;i<=n;i++) vis[i][i]=true;
	for(int i=1;i<=l1;i++){
		for(int j=l1+1;j<=l2;j++){
			if(!vis[i][j] && !vis[j][i]){
				for(int k=l2+1;k<=n;k++){
					if(!vis[k][j]&&!vis[k][i]){
						x.push_back(i);
						y.push_back(j);
						z.push_back(k);
						vis[k][j]=vis[j][k]=vis[k][i]=vis[i][k]=vis[i][j]=vis[j][i]=true;
                        break;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!vis[i][j] && !vis[j][i]){
				for(int k=n;k>=1;k--){
					if(!vis[k][j]&&!vis[k][i]){
						x.push_back(i);
						y.push_back(j);
						z.push_back(k);
						vis[k][j]=vis[j][k]=vis[k][i]=vis[i][k]=vis[i][j]=vis[j][i]=true;
                        break;
					}
				}
			}
		}
	}
	printf("%d\n",x.size());
	for(int i=0;i<x.size();i++){
		printf("%d %d %d\n",x[i],y[i],z[i]);
	}
	return 0;
}