// Problem: E2. Rubik's Cube Coloring (hard version)
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/E2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
ll dp[65][6];
const ll mod=1e9+7;
ll qpow(ll a,int b)
{
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin>>k;
	for(int i=0;i<6;i++){
		dp[1][i]=1;
	}
	int kk[6]={1,0,3,2,5,4};
	for(int i=2;i<=k;i++){
		for(int j=0;j<6;j++){
			for(int o=0;o<6;o++){
				for(int l=0;l<6;l++){
					if(j!=o&&kk[j]!=o&&j!=l&&kk[j]!=l){
						dp[i][j]+=(dp[i-1][o]*dp[i-1][l])%mod;
						dp[i][j]%=mod;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<6;i++){
		ans=(ans+dp[k][i])%mod;
	}
	ll lim=(1<<(k-1));
	int n;
	cin>>n;
	map<ll,int> mp;
	queue<ll> q;
	//queue<pair<ll,int> > q;
	for(int i=0;i<n;i++){
		ll v;
		string s;
		cin>>v>>s;
		int vv;
		switch(s[0]){
			case 'w': vv=1;break;
			case 'y': vv=1;break;
			case 'g': vv=2;break;
			case 'b': vv=2;break;
			case 'r': vv=4;break;
			case 'o': vv=4;break;
		}
		mp[v]=vv;
		q.push(v);
	}
	set<int> sets;
	bool flag=true;
	while(q.size()&&flag){
		ll a=q.front();
		cout<<a<<endl;
		q.pop();
		if(sets.count(a)) continue;
		sets.insert(a);
		if(mp[a]==5||mp[a]==3||mp[a]==6){
			continue;
		}
		if(a!=1){
			if(!mp.count(a/2)){
				mp[a/2]=7;
			}
			mp[a/2]=mp[a/2]^mp[a];
			if(mp[a/2]==0) flag=false; 
			q.push(a/2);
		}
		if(a<lim){
			if(!mp.count(a*2)){
				mp[a*2]=7;
			}
			mp[a*2]=mp[a*2]^mp[a];
			if(mp[a*2]==0) flag=false; 
			q.push(a*2);
			
			if(!mp.count(a*2+1)){
				mp[a*2+1]=7;
			}
			mp[a*2+1]=mp[a*2+1]^mp[a];
			if(mp[a*2+1]==0) flag=false; 
			q.push(a*2+1);
		}
	}
	int cnt=0;
	for(auto [a,b]:mp){
		if(b==5||b==3||b==6) continue;
		else cnt++;
		cout<<a<<" "<<b<<endl;
	}
	if(!flag) ans=0;
	cout<<cnt<<endl;
	return 0;
}