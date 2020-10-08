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
ll dp[30][15][10][10][10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	while(cin>>n){
		vector<int> cnt(5);
		for(i=0;i<n;i++){
			cin>>cnt[i];
		}
		dp[0][0][0][0][0]=1;
		for(int i=1;i<=cnt[0];i++){
			for(int j=0;j<=cnt[1]&&j<=i;j++){
				for(int k=0;k<=cnt[2]&&k<=j;k++){
					for(int l=0;l<=cnt[3]&&l<=k;l++){
						for(int o=0;o<=cnt[4]&&o<=l;o++){
							ll &now=dp[i][j][k][l][o];
							now=0;
							if(i-1>=j) now+=dp[i-1][j][k][l][o];
							if(j-1>=k) now+=dp[i][j-1][k][l][o];
							if(k-1>=l) now+=dp[i][j][k-1][l][o];
							if(l-1>=o) now+=dp[i][j][k][l-1][o];
							if(o-1>=0) now+=dp[i][j][k][l][o-1];
						}
					}
				}
			}
		}
		cout<<dp[cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]]<<endl;
	}
	return 0;
}
