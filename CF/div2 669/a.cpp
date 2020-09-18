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
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int>ans;
		ans.clear();
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		if(n==2){
			if(num[0]&&num[1]){
				cout<<2<<endl;
				cout<<1<<" "<<1<<endl;
			}else{
				cout<<1<<endl;
				cout<<0<<endl;
			}
		}else{
			int cnt[3];
			for(i=1;i<=n/3;i++){
				cnt[0]=cnt[1]=0;
				for(j=(i-1)*3;j<i*3;j++){
					cnt[num[j]]++;
				}
				if(cnt[0]>=2){
					ans.push_back(0);
					ans.push_back(0);
				}else{
					ans.push_back(1);
					ans.push_back(1);
				}
			}
			cout<<ans.size()<<endl;
			for(i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}