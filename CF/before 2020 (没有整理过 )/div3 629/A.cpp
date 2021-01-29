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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	int a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		a%=b;
		if(a) cout<<b-a<<endl;
		else cout<<0<<endl;
	}
	return 0;
}