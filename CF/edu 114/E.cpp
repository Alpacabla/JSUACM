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
const int mod=998244353;
int cnt1[max_n],cnt2[max_n],cnt3[max_n],cnt4[max_n];
int cntcnt,cntcntcnt;
map<pair<int,int>,int>mp;
int k1,k2;
int flag1,flag2;
int none;

void del(int *cnt,int *cnt1,int x,int &kk,int &flag,int &v){
	if(--cnt[x]==0){
		v--;
		if(cnt1[x]){
			flag--;
		}else{
			kk++;	
		}
	}
	return ;
}
void add(int *cnt,int *cnt1,int x,int &kk,int &flag,int &v){
	if(cnt[x]++==0){
		v++;
		if(cnt1[x]){
			flag++;
		}else{
			kk--;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	pow2[0]=1;
	for(int i=1;i<max_n;i++){
		pow2[i]=pow2[i-1]*2%mod;
	}
	k1=n,k2=m;
	int ans=0;
	int vv=0;
	int sta[4][2]={
		1,0,
		0,1,
		-1,0,
		0,-1
	};
	for(int i=1;i<=k;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(z==-1){
			if(mp.count({x,y})){
				int v=mp[{x,y}];
				if(y%2==v) del(cnt1,cnt2,x,k1,flag1,x%2?cntcnt:cntcntcnt);
				else del(cnt2,cnt1,x,k1,flag1,!(x%2)?cntcnt:cntcntcnt);
				if(x%2==v) del(cnt3,cnt4,y,k2,flag2,none);
				else del(cnt4,cnt3,y,k2,flag2,none);
				mp.erase({x,y});
			}
			
		}else{
			//if(z==1){
			if(mp.count({x,y})){
				int v=mp[{x,y}];
				if(y%2==v) del(cnt1,cnt2,x,k1,flag1,x%2?cntcnt:cntcntcnt);
				else del(cnt2,cnt1,x,k1,flag1,!(x%2)?cntcnt:cntcntcnt);
				if(x%2==v) del(cnt3,cnt4,y,k2,flag2,none);
				else del(cnt4,cnt3,y,k2,flag2,none);
				mp.erase({x,y});
			}
			mp[{x,y}]=z;
			if(y%2==z) {add(cnt1,cnt2,x,k1,flag1,x%2?cntcnt:cntcntcnt);}
			else {add(cnt2,cnt1,x,k1,flag1,!(x%2)?cntcnt:cntcntcnt);}
			if(x%2==z) add(cnt3,cnt4,y,k2,flag2,none);
			else add(cnt4,cnt3,y,k2,flag2,none);
			//}else{
				
			//}
		}
		if(flag1&&flag2) cout<<0<<endl;
		else{
			if(k1==n&&k2==m){
				cout<<(pow2[k1]+pow2[k2]-2)%mod<<endl;
			}else{
				int ans=0;
				if(!flag1) ans=pow2[k1];
				if(!flag2) ans=(ans+pow2[k2])%mod;
				if(!flag1&&!flag2&&!(cntcnt&&cntcntcnt)) ans=(ans-1+mod)%mod;
				cout<<ans<<endl;
			}
		}
		
	}
	return 0;
}

/*
0 1 
    0 
    
0 1 0
0 1 0

0 1 1
1 0 0
*/