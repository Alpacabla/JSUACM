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
bool vis[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		int num;
		cin>>n;
		int lim=n<<1;
		vector<int> ans;
		ans.clear();
		for(i=1;i<=n;i++) vis[i]=false;
		for(i=1;i<=lim;i++){
			cin>>num;
			if(!vis[num]){
				ans.push_back(num);
				vis[num]=true;
			}
		}
		for(i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}