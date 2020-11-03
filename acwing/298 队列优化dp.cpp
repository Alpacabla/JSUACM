/*
link: https://www.acwing.com/problem/content/300/
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
struct node{
	int s,l,p;
	bool operator < (const node & a) const {
		return s<a.s;
	}
}nodes[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>nodes[i].l>>nodes[i].p>>nodes[i].s;
	}
	sort(nodes+1,nodes+1+m);
	for(int i=1;i<=m;i++){
		int now=m&1,last=m&1;
		int ll=nodes[i].s-nodes[i].l,r=nodes[i].s+nodes[i].l;
		deque<int> q;
		while(!q.empty()) q.pop_front();
		for(int j=1;j<=n;j++){
			if(j>ll&&j<=nodes[i].s){
				while(!q.empty()&&j-q.front()>=nodes[i].l){
					q.pop_front();
				}
				while(!q.empty()&&dp[q.back()-1][last]+(j-q.back()+1)*nodes[i].p<dp[j-1][last]+nodes[i].p){
					q.pop_back();
				}
				q.push_back(j);
			}
			if(j<nodes[i].s||j>=r){
				dp[j][now]=max(dp[j-1][now],dp[j][last]);
				continue;
			}
			if(j>=nodes[i].s){
				while(!q.empty()&&j-q.front()>=nodes[i].l){
					q.pop_front();
				}
				if(q.empty()) dp[j][now]=max(dp[j-1][now],dp[j][last]);
				else dp[j][now]=max(max(dp[j-1][now],dp[j][last]),(j-q.front()+1)*nodes[i].p+dp[q.front()-1][last]);
			}
		}
	}
	cout<<dp[n][m&1]<<endl;
	return 0;
}