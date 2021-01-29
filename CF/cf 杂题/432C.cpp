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
const int max_n=1e5+5;
int pri[max_n],tot;
bool vis[max_n];
void init(int n)
{
	tot=0;
	for(int i=2;i<=n;i++){
		if(!vis[i]) pri[tot++]=i;
		for(int j=0;j<tot&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0) break;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	init(n);
	vector<int> a(n+1),ind(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ind[a[i]]=i;
	}
	vector<int> ans1,ans2;
	function<void(int,const int)> fun;
	fun=[&fun,&ind,&ans1,&ans2,&a](int n,const int i) -> void {
		if(ind[i]==n) return ;
		int d=ind[i]-n+1;
		int k=upper_bound(pri,pri+tot,d)-pri;
		k-=1;
		fun(n+pri[k]-1,i);
		ans1.push_back(n);
		ans2.push_back(n+pri[k]-1);
		ind[a[n]]=n+pri[k]-1;
		ind[a[n+pri[k]-1]]=n;
		swap(a[n],a[n+pri[k]-1]);
		return ;
	};
	for(int i=1;i<=n;i++){
		fun(i,i);
	}
	cout<<ans1.size()<<endl;
	for(int i=0;i<ans1.size();i++){
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}