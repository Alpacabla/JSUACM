#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=5e5+5;
int sum[26][max_n],sufsum[26][max_n];
bool check(string s1,string s2,string s)
{
	int now=1;
	for(int i=0;i<s2.size();i++){
		string t="";
		int j=0;
		while(j<s1.size()&&now<s.size()&&s[now]==s1[j]){
			if(s1[j]!=s2[i]) t+=s1[j];
			j++;
			now++;
		}
		if(now>s.size()) return false;
		if(j!=s1.size()) return false;
		s1=t;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		s=" "+s;
		bool vis[26];
		for(int i=0;i<26;i++){
			char ch=i+'a';
			sum[i][0]=sufsum[i][s.size()]=0;
			for(int j=1;j<s.size();j++){
				sum[i][j]=sum[i][j-1]+(ch==s[j]);
				if(!vis[i]) vis[i]=(ch==s[j]);
			}
			for(int j=(int)s.size()-1;j>=1;j--){
				sufsum[i][j]=sufsum[i][j+1]+(ch==s[j]);
			}
		}
		string ss;
		struct node{
			int ind;
			char ch;
			bool operator < (const node a) const{
				return ind<a.ind;
			}
		};
		vector<node> b;
		for(int i=0;i<26;i++){
			if(vis[i]){
				for(int j=1;j<s.size();j++){
					if(sum[i][j]&&sufsum[i][j+1]==0){
						b.push_back((node){j,(char)(i+'a')});						
						break;
					}
				}
			}
		}
		sort(b.begin(),b.end());
		string ans2;
		int start=0;
		bool flag=true;
		for(int i=0;i<b.size();i++){
			ans2+=b[i].ch;
			start+=sum[b[i].ch-'a'][s.size()-1]/(i+1);
			if(sum[b[i].ch-'a'][s.size()-1]%(i+1)!=0){
				flag=false;
				break;
			}
		}
		
		string ans;
		for(int i=1;i<=start;i++){
			ans+=s[i];
		}
		if(!flag){
			cout<<-1<<endl;
		}else{
			if(check(ans,ans2,s)){
				cout<<ans<<" "<<ans2<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
	}
	
	return 0;
}