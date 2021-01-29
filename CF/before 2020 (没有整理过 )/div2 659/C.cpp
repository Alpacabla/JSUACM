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
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		string s1,s2;
		cin>>s1;
		cin>>s2;
		int ans=0;
		bool flag=false;
		for(i=0;i<s1.size();i++){
			if(s2[i]<s1[i]){
				cout<<-1<<endl;
				flag=true;
				break;
			}
		}
		if(flag) continue;
		for(i=1;i<20;i++){
			if(s1==s2) break;
			bool flag=true;
			for(j=0;j<s1.size();j++){
				if(s1[j]=='a'+i-1&&s2[j]!=s2[j]){
					s1[j]='a'+i;
					flag=false;
				}
			}
			if(!flag) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}