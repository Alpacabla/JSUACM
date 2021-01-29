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
const ll MAX=1e10;
ll num[1000000];
int ans[100000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	ll l,r;
	int n;
	int i;
	ll j;
	for(i=0,j=1;j<=MAX;i++){
		num[i]=j;
		j+=i+2;
		if(j<100) cout<<num[i]<<" ";
	}
	cout<<num[0]<<endl;
	int sta[10]={1,2,1,3,2,3};
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		int k=lower_bound(num,num+i,l)-num;
	}
	return 0;
}