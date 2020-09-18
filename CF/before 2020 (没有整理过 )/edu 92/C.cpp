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
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int ans=int_inf;
		for(i='0';i<='9';i++){
			for(j='0';j<='9';j++){
				int flag=true;
				int cnt=0;
				for(int k=0;k<s.size();k++){
					if(flag){
						if(s[k]==i){
							cnt++;
							flag=false;
						}
					}else{
						if(s[k]==j){
							cnt++;
							flag=true;
						}
					}
				}
				if(i==j){
					ans=min(ans,(int)(s.size()-cnt));
				}else{
					if(!flag) cnt--;
					ans=min(ans,(int)(s.size()-cnt));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}