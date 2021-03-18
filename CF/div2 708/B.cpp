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
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> book(m+1);
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			book[a[i]%m]++;
		}
		int ans=0;
		for(int i=1;i<m;i++){
			if(book[i]){
				int max1=max(book[i],book[m-i]);
				int min1=min(book[i],book[m-i]);
				if(max1==min1) ans+=1;
				else{
					ans+=max1-min1;
				}
				book[i]=0;
				book[m-i]=0;
			}
		}
		if(book[0]||book[m]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}