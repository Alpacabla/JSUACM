/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
struct node{
	int a,b;
	bool operator < (const node aa) const {
		return a>aa.a;
	}
}a[max_n];
ll sum2[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		ll m;
		cin>>n>>m;
		vector<node> a1(1),a2(1);
		for(int i=1;i<=n;i++){
			cin>>a[i].a;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].b;
			if(a[i].b==1) a1.push_back(a[i]);
			else a2.push_back(a[i]);
		}
		sort(a1.begin()+1,a1.end());
		sort(a2.begin()+1,a2.end());
		sum2[0]=0;
		for(int i=1;i<a2.size();i++){
			sum2[i]=sum2[i-1]+a2[i].a;
		}
		int ans=int_inf;
		ll sum1=0;
		for(int i=0;i<a1.size();i++){
			sum1+=a1[i].a;
			int k=int(lower_bound(sum2,sum2+a2.size(),m-sum1)-sum2);
			if(k!=a2.size()){
				ans=min(ans,i+2*k);
			}
		}
		if(ans==int_inf) cout<<-1<<endl;
		else cout<<ans<<endl; 
	}
	return 0;
}