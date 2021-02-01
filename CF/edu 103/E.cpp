/*
link: 
tags: 看错题意多写50行
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
string s[max_n];
vector<vector<int> > pos;
int _spos[max_n];
int trie[max_n*5][27],ind[max_n*5];
int head[max_n],nxt[max_n<<4],to[max_n<<4];
int vis[max_n];
int tot;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int k;
inline int insertToTrie(string &s,int n)
{
	static int tot=0;
	int now=0;
	int i;
	for(i=0;i<k-1;i++){
		int a;
		if(s[i]<='z'&&s[i]>='a') a=s[i]-'a';
		else a=26;
		trie[now][a]=((trie[now][a]==0)?++tot:trie[now][a]);
		now=trie[now][a];
	}
	int a;
	if(s[i]<='z'&&s[i]>='a') a=s[i]-'a';
	else a=26;
	if(trie[now][a]){
		now=trie[now][a];
		pos[ind[now]].push_back(n);
	}else{
		now=trie[now][a]=++tot;
		ind[now]=pos.size();
		pos.push_back((vector<int>){});
		pos[ind[now]].push_back(n);
	}
	return now;
}
string ss;
int num;
string sss;
int sspos;
vector<int> inds;
inline void dfs(int a,int now)
{
	if(a==k){
		if(sss==s[num]) sspos=ind[now];
		else inds.push_back(ind[now]);
		return ;
	}
	sss[a]='_';
	if(trie[now][26]) dfs(a+1,trie[now][26]);
	
	sss[a]=ss[a];
	if(trie[now][sss[a]-'a']) dfs(a+1,trie[now][sss[a]-'a']);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	pos.push_back((vector<int>){});
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		insertToTrie(s[i],i);
	}
	sss.resize(k);
	bool flag=true;
	for(int i=0;i<m;i++){
		inds.clear();
		sspos=-1;
		cin>>ss>>num;
		dfs(0,0);
		if(sspos==-1) flag=false;
		else{
			for(int i=0;i<inds.size();i++){
				add(sspos,inds[i]);
				vis[inds[i]]++;
			}
			if(_spos[sspos]==0) _spos[sspos]=num;
			else{
				if(_spos[sspos]!=num) flag=false;
			}
		}
	}
	if(!flag){
		cout<<"NO"<<endl;
	}else{
		queue<int> q;
		for(int i=1;i<pos.size();i++){
			if(vis[i]==0){
				q.push(i);
			}
		}
		vector<int> ans;
		while(!q.empty()){
			int a=q.front();
			if(_spos[a]) ans.push_back(_spos[a]);
			for(int i=0;i<pos[a].size();i++){
				if(pos[a][i]!=_spos[a]) ans.push_back(pos[a][i]);
			}
			q.pop();
			for(int j=head[a];j;j=nxt[j]){
				int &u=to[j];
				vis[u]--;
				if(vis[u]==0){
					q.push(u);
				}
			}
		}
		if(ans.size()==n){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}