#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
const int max_n=2e5+5;
ll sum;
map<ll,int>sum1;
int main()
{
	int i;
	int n;
	int num;
	cin>>n;
	ll t=0;
	ll ans=0;
	int right=0;
	sum1[0]=0;
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		sum=t+num;
		if(sum1.find(sum)!=sum1.end()){
			right=max(sum1[sum]+1,right);
		}
		ans+=i-right;
		sum1[sum]=i;
		t=sum;
	}
	cout<<ans<<endl;
	return 0;
}