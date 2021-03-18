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
bool judge(int w,int k1,int k2)
{
	int res=0;
	if(k1<k2){
		swap(k1,k2);
	}
	if(k1%2==0&&k2%2==0){
		res=k2/2+k1/2;
	}
	if(k1%2==1&&k2%2==1){
		res=k2+(k1-k2)/2;
	}
	if(k1%2==1&&k2%2==0){
		res=k2/2+k1/2;
	}
	if(k1%2==0&&k2%2==1){
		res=k2/2+k1/2;
	}
	return res>=w;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,k1,k2;
		cin>>n>>k1>>k2;
		int w,b;
		cin>>w>>b;
		bool flag=true;
		if(!judge(w,k1,k2)) flag=false;
		//cout<<flag<<endl;
		if(!judge(b,n-k1,n-k2)) flag=false;
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}