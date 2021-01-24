#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=3e5+5;
vector<int> e[max_n];
vector<int> ans;
int nxt[max_n],last[max_n];
int fa[max_n];
int du[max_n];
bool vis[max_n],vis1[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	int start;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a==0) start=i;
		else{
			du[i]=1;
			e[a].push_back(i);
			fa[i]=a;
		}
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		nxt[a]=b;
		last[b]=a;
		e[a].push_back(b);
		du[b]++;
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(last[i]||nxt[i]){
				int start=i;
				while(last[start]){
					start=last[start];
					if(start==i){
						flag=false;
						break;
					}
				}
				vis[start]=true;
				vis1[start]=true;
				if(!flag) break;
				vector<int> a;
				int t=nxt[start];
				while(t){
					vis[t]=true;
					vis1[t]=true;
					a.push_back(t);
					t=nxt[t];
				}
				for(int j=0;j<a.size();j++){
					if(!vis1[fa[a[j]]]){
						e[fa[a[j]]].push_back(start);
						du[start]++;
					}
				}
				vis1[start]=false;
				for(int j=0;j<a.size();j++){
					vis1[a[j]]=false;
				}
			}
		}
	}
	if(!flag){
		cout<<0<<endl;
		return 0;
	}
	vector<int> ans;
	stack<int> sta;
	int nxt1=0;
	sta.push(start);
	while(nxt1||sta.size()){
		int now;
		if(nxt1){
			now=nxt1;
			nxt1=0;
		}else{
			now=sta.top();
			sta.pop();
		}
		ans.push_back(now);
		for(int i=0;i<e[now].size();i++){
			du[e[now][i]]--;
			if(du[e[now][i]]==0&&e[now][i]!=nxt[now]){
				sta.push(e[now][i]);
			}
		}
		if(nxt[now]){
			if(du[nxt[now]]==0){
				nxt1=nxt[now];
			}else{
				flag=false;
			}
		}
	}
	if(flag&&ans.size()==n){
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}