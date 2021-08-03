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
//#define endl '\n'
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> d(n+2);
		for(int i=1;i<=m;i++){
			int l,r;
			cin>>l>>r;
			if(l>r){
				d[r+1]-=1;
				d[1]+=1;
				d[l]+=1;
				d[n+1]-=1;
			}else{
				d[l]+=1;
				d[r+1]-=1;
			}
		}
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			d[i]+=d[i-1];
			a[i]=d[i];
		}
		vector<int> l1,r1;
		int l=1,r=n;
		for(int i=1;i<=n;i++){
			if(a[i]){
				l1.push_back(i);
				while(a[i]&&i<=n){
					i++;
				}
				r1.push_back(i-1);
			}
		}
		//cout<<l1.size()<<endl;
		vector<int> ind(l1.size());
		for(int i=0;i<l1.size();i++) ind[i]=i;
		sort(ind.begin(),ind.end(),[&r1](const int a,const int b) -> bool{
			return r1[a]<r1[b];
		});
		vector<int> ans1,ans2;
		for(int i=0;i<ind.size();i++){
			int &l=l1[ind[i]],&r=r1[ind[(i-1+ind.size())%ind.size()]];
			ans1.push_back(l),ans2.push_back(r);
		}
		cout<<ans1.size()<<endl;

		for(int i=0;i<ans1.size();i++){
			cout<<ans1[i]<<" "<<ans2[i]<<endl;
		}
	}
	return 0;
}