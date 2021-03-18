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
const int max_m=1e7+5;
const int max_n=2e5+5;
const int lim=1e7;
int pro[max_m];
int last[max_m];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	for(int i=1;i<=lim;i++) pro[i]=i;
	for(int i=2;i*i<=lim;i++){
		for(int j=i*i;j<=lim;j+=i){
			while(pro[j]%(i*i)==0){
				pro[j]/=i*i;
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int max1=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(last[pro[a[i]]]>=max1){
				ans++;
				max1=i;
			}
			last[pro[a[i]]]=i;
		}
		for(int i=1;i<=n;i++){
			last[pro[a[i]]]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}