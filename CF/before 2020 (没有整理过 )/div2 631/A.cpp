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
int vis[205];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,num;
	int n,x;
	int i;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n>>x;
		for(i=0;i<n;i++){
			cin>>num;
			vis[num]=1;
		}
		i=1;
		while(x){
			if(!vis[i]) x--;
			i++;
		}
		while(vis[i]) i++;
		i--;
		cout<<i<<endl;
	}
	return 0;
}