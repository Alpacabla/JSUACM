// Problem: F. Red-Black Number
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
bool dp[42][42][42][42];
int from1[42][42][42][42],from2[42][42][42][42];
bool xx[42][42][42][42];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,a,b;
		cin>>n>>a>>b;
		string s;
		cin>>s;
		memset(dp,false,sizeof(dp));
		memset(from2,false,sizeof(from2));
		memset(from1,false,sizeof(from1));
		memset(xx,false,sizeof(xx));
		dp[0][0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++){
				for(int l=0;l<a;l++){
					for(int o=0;o<b;o++){
						if(dp[i][j][l][o]){
							dp[i+1][j+1][(l*10+s[i]-'0')%a][o]=dp[i][j][l][o];
							dp[i+1][j][l][(o*10+s[i]-'0')%b]=dp[i][j][l][o];
							
							from1[i+1][j+1][(l*10+s[i]-'0')%a][o]=l;
							from1[i+1][j][l][(o*10+s[i]-'0')%b]=l;
							
							from2[i+1][j+1][(l*10+s[i]-'0')%a][o]=o;
							from2[i+1][j][l][(o*10+s[i]-'0')%b]=o;
							
							xx[i+1][j+1][(l*10+s[i]-'0')%a][o]=0;
							xx[i+1][j][l][(o*10+s[i]-'0')%b]=1;
						}
					}
				}
			}
		}
		int v;
		int min1=int_inf;
		
		for(int j=1;j<n;j++){
			if(dp[n][j][0][0]){
				if(abs(n-j-j)<=min1){
					min1=abs(n-j-j);
					v=j;
				}
			}
		}
		if(min1==int_inf){
			cout<<-1<<endl;
		}else{
			string s;
			s.resize(n);
			int xxx,yyy;
			xxx=yyy=0;
			for(int i=n;i>=1;i--){
				//cout<<v<<endl;
				//cout<<xxx<<" "<<yyy<<endl;
				int x=from1[i][v][xxx][yyy],y=from2[i][v][xxx][yyy];
				if(xx[i][v][xxx][yyy]==0){
					v-=1;
					s[i-1]='R';
				}else{
					s[i-1]='B';
				}
				xxx=x,yyy=y;
			}
			cout<<s<<endl;
		}
	}
	return 0;
}