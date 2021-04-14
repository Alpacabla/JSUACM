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
const int max_n=2e5+5;
struct node{
	int val,ind;
	bool operator < (const node a) const {
		return val>a.val;
	}
};
int pa[max_n];
inline int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
bool merge(int a,int b)
{
	a=find(a),b=find(b);
	if(a==b) return false;
	else{
		pa[a]=b;
		return true;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		ll p;
		cin>>n>>p;
		priority_queue<node> q;
		vector<int> a(n+1),add(n+1);
		vector<bool> vis(n+1);
		memset(pa,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			q.push((node){a[i],i});
		}
		ll ans=0;
		while(q.size()){
			node t=q.top();
			q.pop();
			if(t.val>=p) break;
			int ind=t.ind,val=t.val;
			for(int i=ind+1;i<=n;i++){
				if(a[i]%a[ind]==0){
					if(!vis[i]){
						ans+=a[ind];
						vis[i]=true;
						add[i]=a[ind];
						merge(i,ind);
					}else{
						if(merge(i,ind)){
							ans+=a[ind];
						}
						break;
					}
				}else break;
			}
			for(int i=ind-1;i>=1;i--){
				if(a[i]%a[ind]==0){
					if(!vis[i]){
						ans+=a[ind];
						vis[i]=true;
						add[i]=a[ind];
						merge(i,ind);
					}else{
						if(merge(i,ind)){
							ans+=a[ind];
						}
						break;
					}
				}else break;
			}
			vis[ind]=true;
			// cout<<"val";
			// cout<<ans<<endl;
		}
		//cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			if(pa[i]==0) ans+=p;
		}
		ans-=p;
		cout<<ans<<endl;
	}
	return 0;
}