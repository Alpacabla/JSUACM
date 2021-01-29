#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
// struct nodes{
// 	int v,ind;
// 	bool operator < (const nodes a) const {
// 		return v<a.v;
// 	}
// }num[max_n];
int cnt[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	map<int,int>mp;
	for(i=1;i<=n;i++){
		int num;
		cin>>num;
		mp[num]=i;
	}
	for(i=1;i<=n;i++){
		int k;
		cin>>k;
		int ind=mp[k];
		int v;
		if(ind-i<=0){
			v=n-(i-ind);
		}else v=ind-i;
		cnt[v]++;
	}
	int max1=-1;
	for(i=1;i<=n;i++){
		max1=max(max1,cnt[i]);
	}
	cout<<max1<<endl;
	return 0;
}