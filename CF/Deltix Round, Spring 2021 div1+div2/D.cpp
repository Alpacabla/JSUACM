// Problem: D. Love-Hate
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int mm=60;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='1') a[i]|=(1ll<<j);
		}
	}
	srand(time(0));
	int half=(n+1)/2;
	int lim=50;
	
	int max1=-1;
	//auto begin = std::chrono::steady_clock::now();
   	mt19937 rnd;
	vector<int> ans(m,0);
	while(lim--){
		int k=(rnd())%n+1;
		vector<int> ind;
		for(int i=0;i<m;i++){
			if(a[k]&(1ll<<i)) ind.push_back(i); 
		}
		int siz=1<<(int)ind.size();
		vector<int> cnt(siz),dp(siz);
		for(int i=1;i<=n;i++){
			int val=0;
			for(int j=0;j<ind.size();j++){
				if(a[i]&(1ll<<ind[j])) val|=(1<<j);
			}
			cnt[val]++;
		}
		dp=cnt;
		for(int i=0;i<ind.size();i++){
			for(int j=0;j<siz;j++){
				if(!(j&(1<<i))) dp[j]+=dp[j^(1<<i)];
			}
		}
		for(int i=0;i<siz;i++){
			if(dp[i]>=half&&__builtin_popcount(i)>max1){
				max1=__builtin_popcount(i);
				vector<int> temp(m,0);
				for(int j=0;j<ind.size();j++){
					if(i&(1<<j)) temp[ind[j]]=1;
				}
				ans=temp;
			}
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}