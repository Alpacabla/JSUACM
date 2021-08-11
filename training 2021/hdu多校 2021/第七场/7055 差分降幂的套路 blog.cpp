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
const int mod=998244353;
char s[max_n];
vector<int> len[30];
int last[30];
vector<int> sum;
vector<int> diff;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%s",&s);
		memset(len,0,sizeof(len));
		for(int i=0;i<26;i++){
			len[i].clear();
			len[i].push_back(0);
		}
		int slen=0;
		for(int i=0;s[i];i++){
			char &ch=s[i];
			len[ch-'a'].push_back(i+1-last[ch-'a']);
			last[ch-'a']=i;
			slen++;
		}
		for(int i=0;i<26;i++){
			if(len[i].size()!=1) len[i].push_back(slen-last[i]);
			else continue;

			sum.resize(len[i].size());
			for(int j=(int)sum.size()-1;j>=0;j--){
				if(j==sum.size()-1) sum[j]=len[i][j];
				else sum[j]=sum[j+1]+len[i][j];
			}

			diff.resize(len[i].size());
			for(int j=1;j<diff.size()-1;j++){
				diff[j]=2*sum[j+1]+2*len[i][j]+len[i][j-1];
				//diff[j]=diff[j-1]+diff[j];
				//diff[j]=diff[j-1]+diff[j];
				//ans=(ans+len[i][j]*diff[j]%mod)%mod;
			}
			for(int j=1;j<diff.size()-1;j++){
				diff[j]=diff[j-1]+diff[j];
			}
			for(int j=1;j<diff.size()-1;j++){
				diff[j]=diff[j-1]+diff[j];
			}
			for(int j=1;j<diff.size()-1;j++){
				ans=(ans+len[i][j]*diff[j]%mod)%mod;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}