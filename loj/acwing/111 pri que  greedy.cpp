/*
link: https://www.acwing.com/problem/content/113/
tags: pri que   greedy  c++11   decltype
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
	int l,r;
	int ind;
	bool operator < (const node a) const{
		if(l==a.l) return r>a.r;
		else return l<a.l;
	}
}nodes[max_n];
int ans[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(i=0;i<n;i++){
		int l,r;
		cin>>nodes[i].l>>nodes[i].r;
		nodes[i].ind=i;
	}
	sort(nodes,nodes+n);
	auto cmp=[](node a,node b) -> bool{ return a.r>b.r;};
	priority_queue<node,vector<node>,decltype(cmp)> q{cmp};
	int cnt=1;
	ans[nodes[0].ind]=1;
	q.push(nodes[0]);
	for(i=1;i<n;i++){
		int r=q.top().r,ind=q.top().ind;
		if(nodes[i].l>r){
			q.pop();
			ans[nodes[i].ind]=ans[ind];
		}else{
			ans[nodes[i].ind]=++cnt;
		}
		q.push(nodes[i]);
	}
	cout<<cnt<<endl;
	for(i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
