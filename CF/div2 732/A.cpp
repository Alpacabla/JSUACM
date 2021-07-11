// Problem: A. AquaMoon and Two Arrays
// Contest: Codeforces - Codeforces Round #732 (Div. 2)
// URL: https://codeforces.com/contest/1546/problem/A
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
		vector<int> a(n+1),b(n+1);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		stack<int> sta1,sta2;
		for(int i=1;i<=n;i++){
			if(a[i]<b[i]){
				while(a[i]<b[i]) sta2.push(i),a[i]++;
			}else{
				if(a[i]>b[i]){
					while(a[i]>b[i]) sta1.push(i),a[i]--;
				}
			}
		}
		if(sta1.size()!=sta2.size()){
			cout<<-1<<endl;
		}else{
			cout<<sta1.size()<<endl;
			while(sta1.size()){
				cout<<sta1.top()<<" "<<sta2.top()<<endl;
				sta1.pop(),sta2.pop();
			}
		}
	}
	return 0;
}