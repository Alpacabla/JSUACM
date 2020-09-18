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

	string s;
	cin>>t;
	while(t--){
		cin>>s;
		//cout<<s<<endl;
		int a=-1,b=-1,c=-1;
		int ans=int_inf;
		int l=0;
		for(i=0;i<s.size();i++){
			if(s[i]=='1') a=i;
			if(s[i]=='2') b=i;
			if(s[i]=='3') c=i;
			if(a!=-1&&b!=-1&&c!=-1){
				while(l!=a&&l!=b&&l!=c){
					l++;
				}
				ans=min(ans,i-l+1);
			}
			//cout<<i<<" "<<l<<endl;
			
		}
		if(a!=-1&&b!=-1&&c!=-1)cout<<ans<<endl;
		else cout<<0<<endl;
	}
	return 0;
}