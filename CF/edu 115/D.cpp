#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> >v(n+1);
		vector<int> cnt(n+1);
		vector<int> a(n+1),b(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			cnt[b[i]]++;
			v[a[i]].push_back(b[i]);
		}
		ll ans=1ll*n*(n-1)*(n-2)/6;
		for(int i=1;i<=n;i++){
			ll sum=0;
			for(int j=0;j<v[i].size();j++){
				sum+=cnt[v[i][j]]-1;
			}
			ans-=sum*(v[i].size()-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}