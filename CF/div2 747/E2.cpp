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
//#define endl '\n'
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
	ll lim=(1<<(k-1));
	int n;
	cin>>n;
	vector<pair<ll,int> > col;
	for(int i=0;i<n;i++){
		ll v;
		string s;
		cin>>v>>s;
		int vv;
		switch(s[0]){
			case 'w': vv=0;break;
			case 'y': vv=1;break;
			case 'g': vv=2;break;
			case 'b': vv=3;break;
			case 'r': vv=4;break;
			case 'o': vv=5;break;
		}
		col.push_back({v,vv});
	}
	map<ll,vector<ll> > last;
	for(int i=k;i>=1;i--){
		map<ll,vector<ll> >temp;
		
		for(auto &[a,b]:last){
			if(!temp.count(a/2)){
				vector<ll> vec(6);
				temp[a/2]=vec;
			}
		}
		for(auto &[a,b]:temp){
			vector<ll> le,r;
			if(last.count(a*2)) le=last[a*2];
			else{
				le.resize(6);
				for(int j=0;j<6;j++){
					le[j]=dp[k-i][j];
				}
			}
			if(last.count(a*2+1)) r=last[a*2+1];
			else{
				r.resize(6);
				for(int j=0;j<6;j++){
					r[j]=dp[k-i][j];
				}
			}
			
			for(int j=0;j<6;j++){
				for(int o=0;o<6;o++){
					for(int l=0;l<6;l++){
						if(j!=o&&kk[j]!=o&&j!=l&&kk[j]!=l){
							b[j]+=(le[o]*r[l])%mod;
							b[j]%=mod;
						}
					}
				}
			}
		}
		last=temp;
		for(auto &[a,b]:col){
			if(a>=(1ll<<(i-1))&&a<(1ll<<(i))){
		 		if(!last.count(a)){
		 			vector<ll> vec(6);
		 			vec[b]=dp[k-i+1][b];
		 			last[a]=vec;
		 		}else{
		 			for(int j=0;j<6;j++){
		 				if(b!=j){
		 					last[a][j]=0;
		 				}
		 			}
		 		}
			}
		}
	}
	ll out=0;
	for(int j=0;j<6;j++){
		out=(out+last[1][j])%mod;
	}
	cout<<out<<endl;
	return 0;
}