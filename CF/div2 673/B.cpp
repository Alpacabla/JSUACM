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
		vector<int> num(n),ans(n);
		set<int> sets;
		sets.clear();
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		for(i=0;i<n;i++){
			if(sets.count(num[i])){
				ans[i]=1;
			}else{
				sets.insert(k-num[i]);
			}
		}
		if(k%2==0){
			k/=2;
			int cnt=0;
			for(i=0;i<n;i++){
				if(num[i]==k) {cnt++;ans[i]=1;}
			}
			for(i=0,j=0;i<n&&j<cnt/2;i++){
				if(num[i]==k){
					j++;
					ans[i]=0;
				}
			}
		}
		
		for(i=0;i<n;i++){
			cout<<(i?" ":"")<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}
