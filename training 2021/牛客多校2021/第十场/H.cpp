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
	int n;
	cin>>n;
	int k=sqrt(n);
	if(k*k!=n) k++;
	bool flag=true;
	vector<int> a((1<<n));
	for(int i=0;i<a.size();i++){
		int cnt0=0,cnt1=0;
		for(int j=0;j<n-1;j++){
			int kk=i^(1<<j);
			if(kk<i){
				if(a[kk]==0) cnt0++;
				else cnt1++;
			}else{
				if(cnt0>k&&cnt1>k){
					flag=false;
				}
				if(cnt0>k){
					a[i]=1;
				}
				if(cnt1>k){
					a[i]=0;
				}
				a[kk]=!a[i];
			}
		}
	}
	for(auto v:a){
		cout<<v;
	}
	cout<<endl;
	return 0;
}