/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int bit[max_n];
void add(int ind)
{
	while(ind){
		bit[ind]++;
		ind-=lowbit(ind);
	}
	return ;
}
int query(const int n,int ind)
{
	int res=0;
	while(ind<=n){
		res+=bit[ind];
		ind+=lowbit(ind);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	string s1,s2;
	cin>>n;
	cin>>s1;
	s2=s1;
	reverse(s2.begin(),s2.end());
	vector<int> ind[30],v(n),now(30);
	for(i=0;i<n;i++){
		ind[s2[i]-'a'].push_back(i+1);
	}
	for(i=0;i<n;i++){
		v[i]=ind[s1[i]-'a'][now[s1[i]-'a']++];
	}
	ll ans=0;
	for(i=0;i<n;i++){
		ans+=1ll*query(n+1,v[i]+1);
		add(v[i]);
	}
	cout<<ans<<endl;
	return 0;
}
