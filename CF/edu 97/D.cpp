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
queue<int> q[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> num(n+1);
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		int now=1;
		vector<int> cnt(n+5);
		cnt[1]=1;
		for(int i=2;i<=n;i++){
			if(!cnt[now]){
				now++;
			}
			int k=1;
			while(i<n&&num[i]<num[i+1]){
				i++;
				k++;
			}
			cnt[now]--;
			cnt[now+1]+=k;
		}
		cout<<now<<endl;
	}
	return 0;
}