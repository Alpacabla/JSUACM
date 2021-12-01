// Problem: D. Guess the Permutation
// Contest: Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1589/problem/D
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
map<pair<int,int>,int> mp;
int q(int l,int r){
	int res;
	auto k=mp.find({l,r});
	if(k!=mp.end()){
		return (*k).second;
	}
	if(l!=r){
		cout<<"? "<<l<<" "<<r<<endl;
		cout.flush();
		cin>>res;
	}else{
		res=1;
	}
	mp[{l,r}]=res;
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
		map<pair<int,int>,int> temp;
		mp.swap(temp);
		
		int inv=q(1,n);
		int l=1,r=n,r1=n;
		while(l<=r){
			int mid=(l+r)>>1;
			int v=q(1,mid);
			if(v==inv){
				r1=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		int l1=1;
		r=r1;
		for(auto [u,z]:mp){
			int x=u.first,y=u.second;
			if(y<r1&&z==0&&y>l1) l1=y;
			if(y<r1&&y>l1&&z!=0&&y<r) r=y;
		}
		l=l1+1;
		while(l<=r){
			int mid=(l+r)>>1;
			int v=q(mid,r1);
			if(v==inv){
				l1=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		
		
		cout<<"! "<<l1<<" "<<r1<<endl;
	}
	
	return 0;
}