#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e6+5;
int dp1[max_n],dp2[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		string s;
		getline(cin,s);
		getline(cin,s);
		//cout<<s<<endl;
		int ans=0;
		for(i=0;i<m;i++){
			int cnt1=0,cnt2=0;
			int k=i;
			while(k<n){
				if(s[k]=='0') cnt1++;
				else cnt2++;
				cout<<k<<endl;
				k+=m;
			}
			ans+=min(cnt1,cnt2);
		}
		cout<<ans<<endl;
	}
	return 0;
}