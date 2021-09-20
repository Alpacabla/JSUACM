// Problem: E. Coloring
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/E
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
const int max_n=1e6+5;
int pow2[max_n];
const int mod=998244353 ;
int cnt1[max_n],cnt2[max_n],cnt3[max_n],cnt4[max_n];
map<pair<int,int> >mp;

int k1,k2;

void del(int *cnt,int x,int &kk){
	if(--cnt[x]==0){
		kk++;
	}
	return ;
}
void add(int *cnt,int x,int &kk){
	if(cnt[x]++==0){
		kk--;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>k>>k;
	pow2[0]=1;
	for(int i=1;i<max_n;i++){
		pow2[i]=pow2[i-1]*2%mod;
	}
	int ans=0;
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	for(int i=1;i<=k;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(z==-1){
			if(mp.count({x,y})){
				int v=mp[{x,y}];
				if(x%2==v) del(cnt1,x,k1);
				else del(cnt2,x,k1);
				if(y%2==v) del(cnt3,y,k2);
				else del(cnt3,x,k2);
				mp.erase({x,y});
			}
			
		}else{
			//if(z==1){
			if(mp.count({x,y})){
				int v=mp[{x,y}];
				if(x%2==v) del(cnt1,x,k1);
				else del(cnt2,x,k1);
				if(y%2==v) del(cnt3,y,k2);
				else del(cnt3,x,k2);
				mp.erase({x,y});
			}
			mp[{x,y}]=z;
			if(x%2==z) add(cnt1,x,k1);
			else add(cnt2,x,k1);
			if(y%2==z) add(cnt3,y,k2);
			else add(cnt3,x,k2);
			//}else{
				
			//}
		}
		if((cnt1&&cnt2)&&(cnt3&&cnt4)){
			ans=0;
		}else{
			
		}
		
	}
	return 0;
}