#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=5e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,c,b;
	cin>>n>>c>>b;
	bool vis[n+5];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=b;i++){
		int a;
		cin>>a;
		vis[a-1]=true;
	}
	string s;
	for(int i=0;i<n;i++) s+='0';
	int k=1;
	if(c%2==1) s[0]='1',k=2,c-=1;
	for(int i=k;i<n&&c;i++){
		if(vis[i]) continue;
		s[i]='1';
		c-=2;
		vis[i+1]=true;
	}
	cout<<s<<endl;
	return 0;
}