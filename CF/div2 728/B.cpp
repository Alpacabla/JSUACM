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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct node{
			int v,ind;
			bool operator < (const node a) const {
				return v<a.v;
			}
		};
		vector<node> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i].v;
			a[i].ind=i;
		}
		int res=0;
		sort(a.begin()+1,a.end());
		for(int i=1;i<=n;i++){
			int lim=2*n/a[i].v;
			for(int j=1;j<i&&a[j].v<=lim;j++){
				if(a[i].ind+a[j].ind==a[i].v*a[j].v){
					res++;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}