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
	while(x<=n){
		res+=bit[x];
		x+=lowbit(x);
	}
	return res;
}
ll solve(string s1,string s2)
{
	ll res=0;
	queue<int> q[4];
	vector<int> a(s1.size());
	int tot=1;
	a[0]=tot;
	for(int i=1;i<s1.size();i++){
		while(i<s1.size()&&s1[i]==s1[i-1]){
			a[i]=tot;
			i++;
		}
		if(i>=s1.size()) break;
		a[i]=++tot;
	}
	for(int i=0;i<s1.size();i++){
		q[k[s1[i]]].push(a[i]);
	}
	n=tot;
	memset(bit,0,sizeof(int)*(tot+3));
	for(int i=0;i<s2.size();i++){
		int t=q[k[s2[i]]].front();
		q[k[s2[i]]].pop();
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
	// cout<<solve("NAAN","AANN")<<endl;
	// cout<<solve("OAANTTON","TNNTAOOA")<<endl;
	cin>>t;
	
	while(t--){
		string s,ans;
		cin>>s;
		ll min1=-1;
		int cnt[4]={0};
		for(int i=0;i<s.size();i++){
			cnt[k[s[i]]]++;
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				for(int k=0;k<4;k++){
					for(int l=0;l<4;l++){
						if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l){
							string s1="";
							int a[4]={i,j,k,l};
							//cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
							for(int o=0;o<4;o++){
								for(int c=0;c<cnt[a[o]];c++){
									s1+=ch[a[o]];
								}
							}
							ll res=solve(s,s1);
							if(res>min1){
								min1=res;
								ans=s1;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}