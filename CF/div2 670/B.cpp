/*
link: https://codeforces.com/contest/1406/problem/B
tags: brute froce 乱做
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
ll num[max_n];
struct node{
	ll a;
	int x,y,q,w;
	bool operator < (const node &z) const{
		return a<z.a;
	}
};
bool vis[max_n];
ll solve(int n)
{
	int i,j;
	vector<node> x;
	x.clear();
	x.push_back((node){(num[0]*num[1]),0,1,0,0});
	x.push_back((node){(num[2]*num[3]),2,3,0,0});
	x.push_back((node){(num[n-1]*num[n-2]),n-1,n-2,0,0});
	x.push_back((node){(num[n-3]*num[n-4]),n-3,n-4,0,0});
	// cout<<x[0].a<<endl;
	// cout<<x[1].a<<endl;
	// cout<<x[2].a<<endl;
	// cout<<x[3].a<<endl;
	// x.push_back(num[2]*num[3]);
	// x.push_back(num[n-1]*num[n-2]);
	// x.push_back(num[n-3]*num[n-4]);

	vector<node> xx;
	xx.clear();
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			int x1=x[i].x,x2=x[j].x,y1=x[i].y,y2=x[j].y;
			if(i!=j&&x1!=x2&&x1!=y2&&x2!=y1&&x2!=x1&&y1!=y2) xx.push_back((node){x[i].a*x[j].a,x[i].x,x[i].y,x[j].x,x[j].y});
		}
	}
	sort(xx.begin(),xx.end());
	// for(i=0;i<xx.size();i++){
	// 	cout<<xx[i].a<<endl;
	// }
	ll res=-ll_inf;
	for(j=0;j<xx.size();j++){
		node temp=xx[j];
		vis[temp.x]=true;
		vis[temp.y]=true;
		vis[temp.q]=true;
		vis[temp.w]=true;
		ll ans=-ll_inf;
		for(i=n-1;i>=0;i--){
			if(!vis[i]){
				//cout<<temp.a<<endl;
				//cout<<num[i]<<endl;
				// cout<<temp.a<<endl;
				// cout<<num[i]<<endl;
				// cout<<temp.x<<" "<<temp.y<<" "<<temp.q<<" "<<temp.w<<endl;
				//ans=ans*temp.a*num[i];
				ans=max(ans,temp.a*num[i]);
				//break;
			}
		}
		vis[temp.x]=false;
		vis[temp.y]=false;
		vis[temp.q]=false;
		vis[temp.w]=false;
		res=max(res,ans);
	}
	
	return res;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n;

	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++) cin>>num[i];
		sort(num,num+n);
		ll ans=solve(n);
		cout<<ans<<endl;
	}
	return 0;
}
