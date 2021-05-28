// Problem: C2. Potions (Hard Version)
// Contest: Codeforces - Codeforces Round #723 (Div. 2)
// URL: https://codeforces.com/contest/1526/problem/C2
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
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	priority_queue<int> q;
	
	ll sum=0;
	int del=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(a[i]<=0) q.push(abs(a[i]));	
		while(sum<0){
			int k=q.top();
			sum+=k;
			q.pop();
			del++;
		}
	}
	cout<<n-del<<endl;
	return 0;
}