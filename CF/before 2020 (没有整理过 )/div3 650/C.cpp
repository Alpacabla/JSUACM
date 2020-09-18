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
	int n,k;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cin>>s;
		int ans=0;
		int cnt=k;
		for(i=0;i<s.size();i++){
			if(s[i]=='1'){
				cnt=0;
			}else{
				cnt++;
				if(cnt>k){
					int temp=i;
					j=0;
					for(;j<=k&&i<s.size();i++){
						if(s[i]=='1') break;
						j++;
					}
					if(i==s.size()||j>k){
						ans++;
						s[temp]='1';
						i=temp-1;
					}else{
						if(s[i]=='1'){
							i--;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}