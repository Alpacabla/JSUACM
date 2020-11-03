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
const int max_n=1.6e4+5;
int dp[max_n][2];
int s[105],l[105],p[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>l[i]>>p[i]>>s[i];
	}
	for(int i=1;i<=m;i++){
		int now=i&1,last=!now;
		int ll=s[i]-l[i],r=s[i]+l[i];
		deque<int> q;
		while(!q.empty()) q.pop_front();
		for(int j=1;j<=n;j++){
			if(j>ll&&j<r){
				while(!q.empty()&&j-q.front()>=l[i]){
					q.pop_front();
					//cout<<"no"<<" ";
				}
				while(!q.empty()&&dp[q.back()-1][last]+(j-q.back()+1)*p[i]<=dp[j][last]+p[i]){
					q.pop_back();
				}
			//if(j==0) cout<<"no"<<endl;
				q.push_back(j);
			}
			if(j<s[i]||j>=r){
				dp[j][now]=max(dp[j-1][now],dp[j][last]);
				//cout<<j<<" "<<q.front()<<"ff";
				//cout<<dp[j][now]<<" ";
				continue;
			}else{
				while(!q.empty()&&dp[q.back()-1][last]+(j-q.back()+1)*p[i]<=dp[j][last]+p[i]){
					q.pop_back();
				}
			//if(j==0) cout<<"no"<<endl;
				q.push_back(j);
				//if(q.empty()) dp[j][now]=max(dp[j-1][now]+p[i],dp[j][last]);
				//else{
					//if(q.front()==0) cout<<"no"<<endl;
					dp[j][now]=max(max(dp[j-1][now],dp[j][last]),(j-q.front()+1)*p[i]+dp[q.front()-1][last]);
				//}
			}
			//cout<<j<<" "<<q.front()<<"ff";
			// while(!q.empty()&&dp[q.back()-1][last]+(j-q.back()+1)*p[i]<=dp[j][last]+p[i]){
			// 	q.pop_back();
			// }
			// //if(j==0) cout<<"no"<<endl;
			// q.push_back(j);
			//cout<<dp[j][now]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i][m&1]<<endl;
	}
	cout<<dp[n][m&1]<<endl;
	return 0;
}