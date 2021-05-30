// Problem: D. Kill Anton
// Contest: Codeforces - Codeforces Round #723 (Div. 2)
// URL: https://codeforces.com/contest/1526/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
int k[150];
int bit[max_n];
int n;
void add(int x)
{
	while(x){
		bit[x]++;
		x-=lowbit(x);
	}
}
int query(int x)
{
	int res=0;
	while(x<=4){
		res+=bit[x];
		x+=lowbit(x);
	}
	return res;
}
ll solve(int *a,string s)
{
	for(int i=1;i<=4;i++) bit[i]=0;
	ll res=0;
	for(int i=0;i<s.size();i++){
		int t=a[k[s[i]]];
		add(t);
		res+=query(t+1);
	}
	return res;
}
char ch[4];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	k['A']=0;
	k['N']=1;
	k['T']=2;
	k['O']=3;
	ch[0]='A';
	ch[1]='N';
	ch[2]='T';
	ch[3]='O';
	
	cin>>t;
	
	while(t--){
		string s,ans;
		cin>>s;
		ll min1=-1;
		int cnt[4]={0};
		for(int i=0;i<s.size();i++){
			cnt[k[s[i]]]++;
		}
		string ss[4];
		int a[4]={0,1,2,3};
		
		for(int i=0;i<4;i++){
			ss[i]=string(cnt[i],ch[i]);
		}
		do{
			ll res=solve(a,s);
			if(res>min1){
				string s1="";
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						if(a[k[ch[j]]]==i) s1+=ss[j];
					}
				}
				min1=res;
				ans=s1;
			}
		}while(next_permutation(a,a+4));
		cout<<ans<<'\n';
	}
	return 0;
}