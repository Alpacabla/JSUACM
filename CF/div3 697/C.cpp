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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		ll a,b,n;
		cin>>a>>b>>n;
		ll sum1,sum2;
		vector<int> vis1(a+1),vis2(b+2);
		vector<multiset<int> > sets(a+1);
		vector<int> aa(n+1),bb(n+1);
		for(int i=1;i<=n;i++){
			cin>>aa[i];
		}
		for(int i=1;i<=n;i++){
			cin>>bb[i];
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll cnt=0;
			ll c1=vis1[aa[i]],c2=vis2[bb[i]];
			cnt=c1+c2;
			cnt-=sets[aa[i]].count(bb[i]);
			vis1[aa[i]]++;
			vis2[bb[i]]++;
			sets[aa[i]].insert(bb[i]);
			ans+=i-1-cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}