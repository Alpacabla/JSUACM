#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
const int max_n=1e5+5;
int num[max_n];
int ans[max_n];
int r[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int i;
	ll sum=0;
	int max1=-1;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>num[i];
		ans[i]=i;
		sum+=(ll)num[i];
		r[i]=i+num[i]-1;
		max1=max(r[i],max1);
	}
	if(sum<(ll)n||max1>n){
		cout<<-1<<endl;
	}else{
		if(max1!=n){
			ans[m+1]=n+1;
			
			for(i=m;i>=1;i--){
				ans[i]=ans[i+1]-num[i];
				if(r[i-1]>=ans[i]-1) break;
			}
		}
		for(i=1;i<=m;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}