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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1),nxt(n+1);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<bool> vis(n+1);
		int tot=1;
		int ind=0;

		int last=0;
		for(int i=0;i<n;i++){
			if(ind<a[i]){
				nxt[last]=a[i];
				last=i;
				cout<<a[i]<<" ";
				ind=a[i];
				vis[ind]=true;
			}else{
				while(vis[tot]) tot++;
				cout<<tot<<" ";
				vis[tot]=true;
			}
		}
		ind=0;
		priority_queue<int> q;
		last=0;
		cout<<endl;
		for(int i=0;i<n;i++){
			if(ind<a[i]){
				for(int j=last+1;j<a[i];j++){
					q.push(j);
				}
				last=a[i];
				cout<<a[i]<<" ";
				ind=a[i];
			}else{
				cout<<q.top()<<" ";
				q.pop();
			}
		}
		cout<<endl;
	}
	return 0;
}