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
const ll lim=2e9+5;
char s[max_n];
ll num[max_n];
int main()
{
	int t;
	int i;
	ll n,k;
	num[1]=1;
	for(i=2;num[i-1]<lim;i++){
		num[i]+=num[i-1]+i;
	}
	int z=i;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(i=0;i<n;i++){
			s[i]='a';
		}
		s[i]='\0';
		int h=lower_bound(num+1,num+z,k)-num;
		s[n-h-1]='b';
		s[n-(k-num[h-1])]='b';
		printf("%s\n",s);
	}
	return 0;
}