// Problem: B. Scenes From a Memory
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
vector<string> pi;
void init(int n)
{
	for(int i=2;i<=n;i++){
		int k=sqrt(i);
		bool flag=true;
		for(int j=2;j<=k;j++){
			if(i%j==0){
				flag=false;
			}
		}
		if(!flag){
			string s;
			int kk=i;
			while(kk){
				s+=(kk%10)+'0';
				kk/=10;
			}
			reverse(s.begin(),s.end());
			pi.push_back(s);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	init(10000);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string ans;
		for(int i=0;i<s.size();i++){
			if(((s[i]-'0')%2==0&&s[i]!='2')||s[i]=='1'){
				ans=s[i];
				break;
			}
		}
		if(ans.size()){
			cout<<1<<endl;
			cout<<ans<<endl;
		}else{
			int len=int_inf;
			for(int i=0;i<pi.size();i++){
				int k=0;
				for(int j=0;j<s.size()&&k<pi[i].size();j++){
					if(s[j]==pi[i][k]){
						k++;
					}
				}
				if(k==pi[i].size()){
					if(len>pi[i].size()){
						len=pi[i].size();
						ans=pi[i];
					}
				}
			}
			cout<<ans.size()<<endl;
			cout<<ans<<endl;
		}
	}
	return 0;
}