// Problem: E. Xum
// Contest: Codeforces - Codeforces Global Round 11
// URL: https://codeforces.com/contest/1427/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	srand(time(0));
	vector<ll> a(1);
	cin>>a[0];
	set<ll> s;
	//
	vector<char> ch;
	vector<pair<ll,ll> > ans;
	s.insert(a[0]^1);
	for(int i=1;i<=1e5-1;i++){
		int flag=rand()%2;
		int x=rand()%a.size(),y=rand()%a.size();
		do{
			x=rand()%a.size(),y=rand()%a.size();
			flag=rand()%2;
		}while(a[x]==0||a[y]==0||(flag?((a[x]^a[y])>(ll)1e12):((a[x]+a[y])>(ll)1e12))||(flag?(s.count(a[x]^a[y]^1)):(s.count((a[x]+a[y])^1))));
		ll v;
		if(flag==0){
			ch.push_back('+');
			ans.push_back({a[x],a[y]});
			v=a[x]+a[y];
			a.push_back(v);
		}else{
			ch.push_back('^');
			ans.push_back({a[x],a[y]});
			v=a[x]^a[y];
			a.push_back(v);
		}
		if(s.count(v)){
			ch.push_back('^');
			ans.push_back({v,v^1});
			break;
		}
		s.insert(v^1);
	}
	cout<<ch.size()<<endl;
	for(int i=0;i<ch.size();i++){
		cout<<ans[i].first<<" "<<ch[i]<<" "<<ans[i].second<<endl;
	}
	return 0;
}