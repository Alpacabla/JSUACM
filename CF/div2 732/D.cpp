// Problem: D. AquaMoon and Chess
// Contest: Codeforces - Codeforces Round #732 (Div. 2)
// URL: https://codeforces.com/contest/1546/problem/D
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
const int max_n=2e5+5;
const ll mod=998244353;
ll qpow(ll a,int b)
{
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll x[max_n],invx[max_n];
inline ll C(int a,int b)
{
    if(a<b||a<0||b<0) return 0;
    return x[a]*invx[b]%mod*invx[a-b]%mod;
}
void init(int n)
{
    invx[0]=x[0]=1;
    for(int i=1;i<=n;i++){
        x[i]=x[i-1]*i%mod;
        invx[i]=qpow(x[i],mod-2);
    }
    return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	init(2e5);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int cnt=0;
		int now=0;
		int b=0;
		for(int i=0;i<n;i++){
			int j=i;
			if(s[j]=='0') continue;
			int k=1;
			while(j<n-1&&s[j]=='1'&&s[j]==s[j+1]){
				j++;
				k++;
			}
			if(k%2){
				b++;
				k--;
			}
			i=j;
			cnt+=k/2;
		}
		if(cnt==0){
			cout<<1<<endl;
		}else{
			cout<<C(cnt+n-(2*cnt)-b,cnt)<<endl;
		}
	}
	return 0;
}