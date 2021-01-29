#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	ll n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(n%2==k%2&&n>=k*k){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}