// Problem: D. Xor of 3
// Contest: Codeforces - Codeforces Round #743 (Div. 2)
// URL: https://codeforces.com/contest/1573/problem/D
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
vector<int> solve(int l,int r)
{
	vector<int> res;
	for(int i=l;i<r;i+=2){
		res.push_back(i);
	}
	for(int i=r-4;i>=l;i-=2){
		res.push_back(i);
	}
	return res;
}
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
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=a[i];
		if(cnt%2){
			cout<<"NO"<<endl;
			continue;
		}
		vector<int> ans;
		
		bool flag=false;
		if(n%2){
			flag=true;
			ans=solve(1,n);
		}else{
			int temp=0;
			for(int i=1;i<a.size();i++){
				temp+=a[i];
				if(i%2==1&&temp%2==0){
					ans=solve(1,i);
					auto ttt=solve(i+1,n);
					for(auto v:ttt){
						ans.push_back(v);
					}
					flag=true;
					break;
				}
			}
			if(!flag){
				int temp=0;
				for(int i=a.size()-1;i>=1;i--){
					temp+=a[i];
					if(i%2==0&&temp%2==0){
						ans=solve(i,n);
						auto ttt=solve(1,i-1);
						for(auto v:ttt){
							ans.push_back(v);
						}
						flag=true;
						break;
					}
				}
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
			cout<<ans.size()<<endl;
			for(auto a:ans){
				cout<<a<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}