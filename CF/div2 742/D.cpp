// Problem: D. Expression Evaluation Error
// Contest: Codeforces - Codeforces Round #742 (Div. 2)
// URL: https://codeforces.com/contest/1567/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
//#define endl '\n'
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
		int sum,n;
		cin>>sum>>n;
		int nn=n;
		vector<int> ans;
		priority_queue<int,vector<int>,greater<int>> q;
		
		int k=1;
		int xx=sum;
		while(sum&&ans.size()+1+q.size()<n){
			if(sum%10){
				if(k==1){
					ans.push_back(1);
				}else{
					q.push(k);
				}
				sum--;
				//sum-=k;
				xx-=k;
			}else{
				k*=10;
				sum/=10;
			}
		}
		sum=xx;
		if(ans.size()+1+q.size()==n&&sum){
			ans.push_back(sum);
		}else{
			while(q.size()&&q.size()+ans.size()<n){
				int k=q.top();
				q.pop();
				int z=k;
				if(k==10){
					while(z&&q.size()+ans.size()+1<n){
						ans.push_back(1);
						z--;
					}
					if(z) ans.push_back(z);
				}else{
					while(z&&q.size()+ans.size()+1<n){
						q.push(k/10);
						z-=k/10;
					}
					if(z) ans.push_back(z);
				}
			}
		}
		while(q.size()){
			ans.push_back(q.top());
			q.pop();
		}
		for(auto a:ans){
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}