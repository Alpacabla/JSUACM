/*
link: https://ac.nowcoder.com/acm/problem/50439
tags: greedy
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
struct node{
	int v,s;
	bool operator < (const node & a) const {
		return s>a.s;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	vector<node> a(n);
	vector<ll> summ(n+1); 
	vector<int> cnt(n+1);
	for(i=0;i<n;i++){
		cin>>a[i].v>>a[i].s;
	}
	int size=0;
	ll sum=0,ans=-1;
	sort(a.begin(),a.end(),[](const node a,const node b) -> bool {
		return a.v>b.v;
	});
	for(j=0,i=1;i<=n;i++){
		sum-=summ[i-1];
		size-=cnt[i-1];
		while(j<n){
			if(a[j].s>=i){
				summ[a[j].s]+=a[j].v;
				size++;
				cnt[a[j].s]++;
				sum+=a[j].v;
			}
			j++;
			if(size==i) break;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
