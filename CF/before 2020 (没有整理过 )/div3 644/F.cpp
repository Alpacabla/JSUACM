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
string s[15];
vector<char>kk[15];
string ts;
bool vis[128];
int n,m;
int flag;
void dfs(int a)
{
	if(flag) return ;
	if(a==m){
		int i,j;
		//for(i=0;i<m;i++){
		//	cout<<ts[i];
		//}
		//cout<<endl;
		//cout<<m<<endl;
		//ts[m]='\0';
		//cout<<ts<<endl;
		for(i=1;i<=n;i++){
			int cnt=0;
			for(j=0;j<m;j++){
				if(ts[j]!=s[i][j]){
					cnt++;
				}
			}
			if(cnt>1){
				break;
			}
		}
		if(i!=n+1){
			return ;
		}else{
			flag=1;
			ts[m]='\0';
			return ;
		}
	}
	int i;
	for(i=0;i<kk[a].size();i++){
		ts[a]=kk[a][i];
		dfs(a+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>s[i];
		}
		ts.resize(m+1);
		for(i=0;i<m;i++){
			kk[i].clear();
		}
		for(i=0;i<m;i++){
			for(j=1;j<=n;j++){
				vis[s[j][i]]=true;
			}
			for(char ch='a';ch<='z';ch++){
				if(vis[ch]){
					kk[i].push_back(ch);
					//cout<<ch<<endl;
				}
			}
			for(j=0;j<kk[i].size();j++){
				vis[kk[i][j]]=false;
				//cout<<kk[i][j]<<endl;
			}
			if(kk[i].size()>2){
				break;
			}
		}
		if(i!=m){
			cout<<"no"<<endl;
			//cout<<-1<<endl;
		}else{
			flag=0;
			dfs(0);
			if(flag){
				cout<<ts<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
	}
	return 0;
}