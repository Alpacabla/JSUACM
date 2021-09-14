// Problem: D. Unshuffling a Deck
// Contest: Codeforces - Codeforces Global Round 11
// URL: https://codeforces.com/contest/1427/problem/D
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
	auto check=[](vector<int> &a) -> int{
		bool flag=true;
		for(int i=1;i<a.size()&&flag;i++){
			if(a[i]!=i) flag=false;
		}
		if(flag) return 1;
		flag=true;
		for(int i=1;i<a.size()&&flag;i++){
			if(a[i]!=a.size()-i+1) flag=false;
		}
		if(flag) return 2;
		return 0;
	};
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int> > ans;
	int res=0;
	int now=0;
	auto find=[](vector<int> &a,int num) -> int{
		for(int i=1;i<a.size();i++) if(a[i]==num) return i;
	};
	auto op=[](vector<int> &a,vector<int> &k) -> void{
		vector<int> v(1);
		int ind=1;
		int n=a.size()-1;
		for(int i=k.size()-1;i>=0;i--){
			for(int j=n-k[i]+1;j<=n;j++) v.push_back(a[j]);
			n-=k[i];
		}
		swap(a,v);
		return ;
	};
	while((res=check(a))==0){
		vector<int> k;
		if(now%2==0){
			for(int i=n;i>n-now;i--){
				k.push_back(1);
			}
			int v=find(a,now+1);
			k.push_back(n-now-v+1);
			if(n-now-(n-now-v+1)) k.push_back(n-now-(n-now-v+1));
			reverse(k.begin(),k.end());
		}else{
			for(int i=1;i<=now;i++){
				k.push_back(1);
			}
			int v=find(a,now+1);
			k.push_back(v-now);
			if(n-(v-now)-now) k.push_back(n-(v-now)-now);
		}
		now++;
		if(k.size()==1){
			continue;
		}
		op(a,k);
		ans.push_back(k);
	}
	if(res==2){
		ans.push_back(vector<int> (n,1));
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].size();
		for(int j=0;j<ans[i].size();j++){
			cout<<" "<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}