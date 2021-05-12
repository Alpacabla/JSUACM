// Problem: D. Similar Arrays
// Contest: Codeforces - 2018-2019 Russia Open High School Programming Contest (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1090/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int cnt[max_n];
int head[max_n],to[max_n<<1],nxt[max_n<<1];
int tot=0;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(n==1){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
		add(a,b);
		add(b,a);
	}
	vector<int> ans(n+1),ans1(n+1);
	vector<bool> vis(n+1);
	bool flag=false;
	int s,e;
	for(int i=1;i<=n;i++){
		if(cnt[i]<n-1){
			flag=true;
			s=i;
			vis[i]=true;
			for(int j=head[i];j;j=nxt[j]){
				int &u=to[j];
				vis[u]=true;
			}
			for(int j=1;j<=n;j++){
				if(!vis[j]){
					e=j;
					break;
				}
			}
			break;
		}
	}
	if(flag){
		cout<<"YES"<<endl;
		int now=3;
		ans[s]=1;
		ans[e]=2;
		for(int i=1;i<=n;i++){
			if(s==i||i==e) continue;
			ans[i]=ans1[i]=now++;
		}
		ans1[s]=2;
		ans1[e]=2;
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			cout<<ans1[i]<<" ";
		}
		cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}