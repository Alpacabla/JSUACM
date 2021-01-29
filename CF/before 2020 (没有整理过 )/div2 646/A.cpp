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
int cnt1[1050],cnt2[1050];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		if(s.size()<=2){
			cout<<0<<endl;
		}else{
			int ans=int_inf;
			memset(cnt1,0,s.size()*4+20);
			memset(cnt2,0,s.size()*4+20);
			for(i=0;i<s.size();i++){
				if(s[i]=='0'){
					cnt1[i]=1;
				}
				if(i!=0)cnt1[i]+=cnt1[i-1];
				//cout<<cnt1[i]<<endl;
			}
			for(i=0;i<s.size();i++){
				if(s[i]=='1'){
					cnt2[i]=1;
				}
				if(i!=0)cnt2[i]+=cnt2[i-1];
				//cout<<cnt2[i]<<endl;
			}
			for(i=0;i<s.size()-1;i++){
				int min1=int_inf;
				min1=min(min1,cnt1[i]+cnt2[s.size()-1]-cnt2[i]);
				//cout<<min1<<endl;
				min1=min(min1,cnt2[i]+cnt1[s.size()-1]-cnt1[i]);
				//cout<<min1<<endl;
				ans=min(ans,min1);
			}
			ans=min(ans,cnt1[s.size()-1]);
			ans=min(ans,cnt2[s.size()-1]);
			cout<<ans<<endl;
		}
	}
	return 0;
}