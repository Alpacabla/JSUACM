/*
link: 
tags: 
*/
#include<vector>
#include<iostream>
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
	int i,j;
	int n;
	while(cin>>n&&n){
		vector<int>d(n+1);
		for(int i=1;i<=n;i++){
			int l,r;
			cin>>l>>r;
			d[l]+=1;
			d[r+1]-=1;
		}
		int now=0;
		for(int i=1;i<=n;i++){
			now+=d[i];
			cout<<now<<(i!=n?" ":"");
		}
		cout<<endl;
	}
	return 0;
}