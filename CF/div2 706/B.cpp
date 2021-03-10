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
		int n,k;
		cin>>n>>k;
		vector<ll> a(n+1);
		set<ll> sets;
		ll s=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sets.insert(a[i]);
		}
		ll max1;
		for(auto x:sets){
			if(s==x){
				s++;
			}
			max1=x;
		}
		bool flag=true;
		int cnt=0;
		for(int i=1;i<=min(k,100);i++){
			while(sets.count(s)==1) s++;
			ll sum=max1+s;
			if(sum%2==1) sum=sum/2+1;
			else sum/=2;
			if(sets.count(sum)==1){
				flag=false;
				break;
			}else{
				cnt++;
				max1=max(max1,sum);
				sets.insert(sum);
			}
		}
		if(flag==false){

			//cout<<'z'<<endl;
			cout<<sets.size()<<endl;
		}else{
			cout<<sets.size()+k-cnt<<endl;
		}
	}
	return 0;
}