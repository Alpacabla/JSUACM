#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int max_n=1e6+5;
char s[max_n];
char ans[max_n];
char t_s[max_n*2];
int dp[max_n*2];
int pre(int start,int end)
{
	int cnt=0;
	int i;
	t_s[cnt++]='~';
	for(i=start;i<=end;i++){
		t_s[cnt++]='#';
		t_s[cnt++]=s[i];
	}
	t_s[cnt++]='#';
	t_s[cnt++]='^';
	return cnt;
}
void manacher(int len)
{
	int i,_i;
	int center=0,r=0;
	len-=1;
	for(i=1;i<len;i++){
		if(i<r){
			_i=(center<<1)-i;
			dp[i]=min(dp[_i],r-i);
		}else dp[i]=0;
		while(t_s[i-1-dp[i]]==t_s[i+1+dp[i]]){
			dp[i]++;
		}
		if(i+dp[i]>r){
			r=i+dp[i];
			center=i;
		}
	}
	return ;
}
int main()
{
	int i,j;
	int t;
	cout<<(char)(14+64);
	cin>>t;
	typedef int a,b;
	a c;
	b d;
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		int l=0,r=len-1;
		while(l<r&&s[l]==s[r]){
			l++,r--;
		}
		if(s[l]==s[r]){
			printf("%s\n",s);
		}else{
			int len1=pre(l,r);
			manacher(len1);
			int max1=0,flag=1;
			len1-=1;
			for(i=1;i<len1;i++){
				if(dp[i]>max1&&dp[i]==i-1){
					max1=dp[i];
					flag=1;
				}
			}
			for(i=len1-1;i>=1;i--){
				if(dp[i]>max1&&dp[i]==len1-i-1){
					max1=dp[i];
					flag=0;
				}
			}
			int cnt=0;
			if(flag) l+=max1;
			for(i=0;i<l;i++){
				ans[cnt++]=s[i];
			}
			ans[cnt++]='\0';
			printf("%s",ans);
			if(!flag) printf("%s",s+r+1-max1);
			else printf("%s",s+r+1);
			printf("\n");
		}
	}
	return 0;
}