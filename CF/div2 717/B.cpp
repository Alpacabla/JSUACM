// Problem: B. AGAGA XOOORRR
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		vector<int> sum1(n+1),sum2(n+1);
		int res=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum1[i]=sum1[i-1]^a[i];
		}
		for(int i=1;i<=n;i++){
			sum2[i]=sum2[i-1]^a[n-i+1];
		}
		bool flag=false;
		for(int i=1;i<n;i++){
			if(sum1[i]==sum2[n-i]){
				flag=true;
				break;
			}
		}
		for(int i=1;i<n&&!flag;i++){
			for(int j=1;j+i<=n&&!flag;j++){
				if((sum1[i]==sum2[j])&&(sum1[i]==(sum1[n-j]^sum1[i]))){
					flag=true;
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}