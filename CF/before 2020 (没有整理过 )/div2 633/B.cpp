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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	int t;
	ll x;
	cin>>t;
	while(t--){
		ll sum;
		cin>>n>>x;
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		sort(num,num+n);
		int ans=0;
		sum=0;
		for(i=n-1;i>=0;i--){
			ans++;
			sum+=num[i];
			ll q=sum/(ll)ans;
			if(q<(ll)x){
				break;
			}
		}
		if(i!=-1) ans-=1;
		cout<<ans<<endl;
	}
	
	return 0;
}