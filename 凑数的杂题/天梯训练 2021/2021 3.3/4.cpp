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
	int i,j;
	int ans=0;
	for(int i=1;i<=100000;i++){
		int k=i;
		int a[6];
		bitset<10> vis;
		bool flag=true;
		for(int j=0;j<5;j++){
			a[j]=i%10;
			if(vis[a[j]]||!a[j]){
				flag=false;
				break;
			}
			vis[a[j]]=true;
			i/=10;
		}
		if(flag){
			int t1,t2,t3,t4;
			t1=a[0]*100+a[1]*10+a[2];
			t2=a[3]*10+a[4];
			t3=a[0]*10+a[2];
			t4=a[3]*100+a[1]*10+a[4];
			//cout<<t1<<" "<<t2<<endl;
			if(t1*t2==t3*t4) ans++;
		}
		i=k;
	}
	cout<<ans<<endl;
	return 0;
}