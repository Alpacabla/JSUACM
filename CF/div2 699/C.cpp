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
	int i,j;
	int n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> a(n+1),b(n+1),c(m+1),ans(m+1);
		vector<stack<int> >to(n+1);
		vector<int> d(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=m;i++){
			cin>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=a[i]){
				to[b[i]].push(i);
			}else{
				d[b[i]]=i;
			}
		}
		int last=0;
		bool flag=true;
		for(int i=m;i>=1&&flag;i--){
			if(to[c[i]].size()){
				ans[i]=to[c[i]].top();
				to[c[i]].pop();
			}else{
				if(last==0){
					if(d[c[i]]) ans[i]=d[c[i]];
					else flag=false;
				}else ans[i]=last;
			}
			last=ans[i];
		}
		for(int i=1;i<=n&&flag;i++){
			if(to[i].size()) flag=false;
		}
		if(flag){
			cout<<"YES\n";
			for(int i=1;i<=m;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}