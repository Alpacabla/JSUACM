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
bool sta[(1<<16)+1000];
struct nodes{
	bool did[5][5];
	char s[5][5];
	int val;
	inline int setval(){
		int v=0,x=1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				v+=(s[i][j]=='+'?x:0);
				x<<=1;
			}
		}
		val=v;
		return v;
	}
};
nodes bfs(nodes start)
{
	queue<nodes> q;
	while(!q.empty()) q.pop();
	q.push(start);
	sta[start.val]=true;
	while(!q.empty()){
		nodes t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(!t.did[i][j]){
					nodes in=t;
					for(int k=0;k<4;k++) in.s[i][k]=(in.s[i][k]=='+'?'-':'+');
					for(int k=0;k<4;k++) in.s[k][j]=(in.s[k][j]=='+'?'-':'+');
					in.s[i][j]=(in.s[i][j]=='+'?'-':'+');
					int v=in.setval();
					in.did[i][j]=true;
					if(v==0) return in;
					if(!sta[v]){
						sta[v]=true;
						q.push(in);
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	nodes s;
	for(i=0;i<4;i++){
		cin>>s.s[i];
	}
	s.setval();
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			s.did[i][j]=0;
		}
	}
	nodes ans;
	if(s.val!=0){
		ans=bfs(s);
	}else ans=s;
	int cnt1=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(ans.did[i][j]) cnt1++;
		}
	}
	cout<<cnt1<<endl;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(ans.did[i][j]){
				cout<<i+1<<" "<<j+1<<endl;
			}
		}
	}
	return 0;
}