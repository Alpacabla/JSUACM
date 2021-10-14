// Problem: A. Elections
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
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
		vector<int> a(3);
		int cnt=0;
		for(int i=0;i<3;i++){
			cin>>a[i];
		}
		
		int max1=max({a[0],a[1],a[2]});
		for(int i=0;i<3;i++){
			cnt+=a[i]==max1;
		}
		for(int i=0;i<3;i++){
			if(cnt>1){
				cout<<(max1+1-a[i])<<" ";
			}else{
				cout<<(max1==a[i]?0:(max1+1-a[i]))<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}