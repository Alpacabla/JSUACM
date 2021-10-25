// Problem: D. Frog Traveler
// Contest: Codeforces - Codeforces Round #751 (Div. 2)
// URL: https://codeforces.com/contest/1602/problem/D
// Memory Limit: 512 MB
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
const int max_n=3e5+5;
bool vis[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	vector<int> pos(1,n);
	int dep=n;
	bool flag=true;
	vis[n]=true;
	int ans=0;
	vector<int> out;
	vector<int> zzz(1,n);
	while(flag){
		ans++;
		vector<int> temp;
		int min1=int_inf,tt;
		for(int i=0;i<pos.size();i++){
			int k=pos[i]-a[pos[i]];
			if(k==0){
				flag=false;
			}
			min1=min(min1,k);
			if(min1==k) {tt=zzz[i];}
		}
		zzz.clear();
		out.push_back(tt);
		if(!flag) break;
		if(min1>=dep){
			ans=-1;
			break;
		}else{
			for(int i=min1;i<=dep;i++){
				int k=i+b[i];
				if(!vis[k]){
					vis[k]=true;
					temp.push_back(k);
					zzz.push_back(i);
				}
			}
		}
		
		dep=min1;
		pos=temp;
	}
	cout<<ans<<endl;
	if(ans==-1) return 0;
	for(int i=1;i<out.size();i++) cout<<out[i]<<" ";
	if(out[out.size()-1]!=0) cout<<0<<endl;
	return 0;
}