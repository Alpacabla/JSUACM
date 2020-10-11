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
bool vis[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		memset(vis,0,sizeof(bool)*(n+2));
		int ans=0;
		int sum=0;
		for(int i=0;i<n;i++){
			int cnt=1;
			while(i<n-1&&s[i]==s[i+1]){
				i++;
				cnt++;
			}
			if(cnt==1){
				sum++;
			}else{
				if(cnt<=sum){
					ans+=cnt;
					sum-=cnt;
				}else{
					ans+=sum;
					cnt-=sum;
					sum=0;
					if(cnt==1){
						sum=1;
					}else{
						if(cnt>=2){
							ans++;
						}
					}
				}
			}
		}
		ans+=sum/2;
		if(sum%2) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
