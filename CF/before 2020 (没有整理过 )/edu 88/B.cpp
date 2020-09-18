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
	int t,n,m,x,y;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>m>>x>>y;
		int ans=0;
		if(2*x<=y){
			for(i=0;i<n;i++){
				cin>>s;
				for(j=0;j<m;j++){
					if(s[j]=='.'){
						ans+=x;
					}
				}
			}
		}else{
			for(i=0;i<n;i++){
				cin>>s;
				for(j=0;j<m;j++){
					if(s[j]=='.'&&s[j+1]=='.'){
						ans+=y;
						j++;
					}else{
						if(s[j]=='.'){
							ans+=x;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}