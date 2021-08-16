// Problem: C. Mocha and Hiking
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/C
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
		for(int i=1;i<=n;i++) cin>>a[i];
		if(a[n]==0){
			for(int i=1;i<=n+1;i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}else{
			if(a[1]==1){
				cout<<n+1;
				for(int i=1;i<=n;i++){
					cout<<" "<<i;
				}
				cout<<endl;
			}else{
				int pos=-1;
				for(int i=1;i<=n;i++){
					if(a[i]==0&&a[i+1]==1&&i<n){
						pos=i;
						break;
					}
				}
				if(pos==-1){
					cout<<-1<<endl;
				}else{
					for(int i=1;i<=pos;i++){
						cout<<i<<" ";
					}
					cout<<n+1<<" ";
					for(int i=pos+1;i<=n;i++){
						cout<<i<<" ";
					}
					cout<<endl;
				}
			}
		}
	}
	return 0;
}