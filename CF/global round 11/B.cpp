/*
link: 
tags: greedy
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
struct node{
	int l,r;
	int len;
	bool operator < (const node a) const {
		return len<a.len;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		vector<node> seg(0),frontier(0);
		for(i=0;i<n&&s[i]=='L';i++);
		if(s[0]=='L') frontier.push_back((node){0,i-1,i});
		for(j=n-1;j>i&&s[j]=='L';j--);
		if(i!=n&&s[n-1]=='L') frontier.push_back((node){j+1,n-1,n-1-(j+1)+1});
		for(;i<=j;i++){
			int l,r;
			int len=0;
			bool flag=true;
			l=i;
			while(i<=j&&s[i]=='L'){
				i++;
				flag=false;
			}
			if(!flag){
				r=i-1;
				len=r-l+1;
				seg.push_back((node){l,r,len});
			}
		}
		sort(seg.begin(),seg.end());
		for(i=0;i<seg.size()&&m>0;i++){
			for(j=seg[i].l;j<=seg[i].r&&m>0;j++,m--){
				s[j]='W';
			}
		}
		for(i=0;i<frontier.size()&&m>0;i++){
			if(frontier[i].l!=0){
				for(j=frontier[i].l;j<=frontier[i].r&&m;j++,m--){
					s[j]='W';
				}
			}else{
				for(j=frontier[i].r;j>=frontier[i].l&&m;j--,m--){
					s[j]='W';
				}
			}
			
		}
		int ans=0;
		if(s[0]=='W') ans=1;
		for(i=1;i<n;i++){
			if(s[i]=='W'){
				ans++;
				if(s[i-1]=='W') ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
