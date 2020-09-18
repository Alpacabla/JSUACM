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
int cnt[131072+5][18];
string s;
int now;
int ans;
int dfs(int a,int start)
{
	if(a==now){
		return s[start]!=('a'+now);
	}
	int add=(1<<(now-a-1));
	return min(dfs(a+1,start+add)+cnt[start][a],dfs(a+1,start)+cnt[start+add][a]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	//cin>>t;
	while(t--){
		int n;
		//cin>>n;
		//cin>>s;
		n=131072;
		s.resize(131072+5);
		for(int i=1;i<=131072;i++){
			s[i]='a';
		}
		if(n==1){
			cout<<(s[0]!='a')<<endl;
			continue;
		}
		ans=int_inf;
		memset(cnt,0,n*sizeof(int)*18);
		int temp=n;
		now=0;
		while(temp!=1){
			temp>>=1;
			for(i=0;i<n;i+=temp){
				int lim=i+temp;
				for(j=i;j<lim;j++){
					if(s[j]!='a'+now){
						cnt[i][now]++;
					}
				}
			}
			now++;
		}
		cout<<dfs(0,0)<<endl;
	}
	return 0;
}