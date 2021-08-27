#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
//#define endl '\n'
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
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		string s;
		vector<int> a(n+1);
		vector<int> sum(n+1);
		vector<vector<int> > ind(4*n+5,vector<int>(0));
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='-') a[i+1]=-1;
			else a[i+1]=1;
		}
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+(i%2?-a[i]:a[i]);
		}
		for(int i=1;i<=n;i++){
			ind[sum[i]+sum[i-1]+2*n].push_back(i);
		}
		while(q--){
			int a,b;
			cin>>a>>b;
			if(sum[b]-sum[a-1]==0){
				cout<<0<<endl;
				continue;
			}
			if((sum[b]-sum[a-1])%2==0){
				cout<<2<<endl;
				cout<<b<<" ";
				b--;
			}else{
				cout<<1<<endl;
			}
			int ss=sum[b]+sum[a-1]+2*n;
			//auto k=lower_bound(ind[ss].begin(),ind[ss].end(),a);
			cout<<*(lower_bound(ind[ss].begin(),ind[ss].end(),a))<<endl;
		}
	}	
	return 0;
}