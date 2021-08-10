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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		vector<double> v(n+1);
		vector<bool> vis1(n+1),vis(n+1),vis2(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(!vis1[i]&&!vis2[i]){
				int k=i;
				stack<int> sta;
				while(!vis1[k]){
					vis1[k]=true;
					sta.push(k);
					k=a[k];
				}
				if(vis[k]||vis2[k]){
					while(sta.size()){
						vis2[sta.top()]=true;
						sta.pop();
					}
					continue;
				}
				ll sum=a[k];
				stack<int> z;
				z.push(k);
				while(sta.top()!=k){
					sum+=a[sta.top()];
					z.push(sta.top());
					vis2[sta.top()]=true;
					sta.pop();
				}
				while(sta.size()){
					vis2[sta.top()]=true;
					sta.pop();
				}
				double val=sum*1.0/z.size();
				while(z.size()){
					v[z.top()]=val;
					vis[z.top()]=true;
					z.pop();
				}
			}
		}
		for(int i=1;i<=n&&flag;i++){
			if(!vis[i]){
				int k=i;
				stack<int> sta;
				ll sum=0;
				while(!vis[k]){
					vis[k]=true;
					sta.push(k);
					sum+=a[k];
					k=a[k];
				}
				if(k==i){
					double val=sum*1.0/sta.size();
					while(sta.size()){
						v[sta.top()]=val;
						sta.pop();
					}
				}else{
					double val=v[k];
					while(sta.size()){
						v[sta.top()]=val;
						sta.pop();
					}
				}
			}
		}
		double z=v[1];
		for(int i=1;i<=n&&flag;i++){
			if(z!=v[i]) flag=false;
		}
		if(!flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}