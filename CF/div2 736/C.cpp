// Problem: C. Web of Lies
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int n,m;
	cin>>n>>m;
	vector<int> cnt(n+1);
	int ans=0;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		cnt[a]++;
		if(cnt[a]==1) ans++;
	}
	int q;
	cin>>q;
	while(q--){
		int sta;
		cin>>sta;
		if(sta==1){
			int a,b;;
			cin>>a>>b;
			if(a>b) swap(a,b);
			cnt[a]++;
			if(cnt[a]==1) ans++;
		}else{
			if(sta==2){
				int a,b;;
				cin>>a>>b;
				if(a>b) swap(a,b);
				cnt[a]--;
				if(cnt[a]==0) ans--;
			}else{
				cout<<n-ans<<endl;
			}
		}
	}
	return 0;
}