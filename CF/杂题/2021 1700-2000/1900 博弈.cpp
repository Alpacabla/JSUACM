// Problem: E. Array Game
// Contest: Codeforces - Bubble Cup 14 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred, Div. 2)
// URL: https://codeforces.com/problemset/problem/1600/E
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
const int max_n=2e5+5;
int l[max_n],r[max_n];
bool dfs(int l1,int r1,vector<int> &a,int last,bool who)
{
	if(l1>r1){
		return who;
	}
	if(!(a[l1]>last&&a[r1]>last)){
		if(!(a[l1]>last||a[r1]>last)){
			return who;
		}else{
			bool cnt;
			if(a[l1]>last){
				cnt=r[l1]%2;
			}
			if(a[r1]>last){
				cnt=l[r1]%2;
			}
			return who==cnt;
		}
	}
	if(who)	return dfs(l1+1,r1,a,a[l1],!who)&dfs(l1,r1-1,a,a[r1],!who);
	else return dfs(l1+1,r1,a,a[l1],!who)|dfs(l1,r1-1,a,a[r1],!who);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	//a[0]=int_inf;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			l[i+1]=l[i]+1;
		}else{
			continue;
		}
	}
	for(int i=n;i>1;i--){
		if(a[i]>a[i-1]){
			r[i-1]=r[i]+1;
		}else{
			continue;
		}
	}
	bool flag=dfs(2,n,a,a[1],1)|dfs(1,n-1,a,a[n],1);
	cout<<(flag?"Alice":"Bob")<<endl;
	return 0;
}