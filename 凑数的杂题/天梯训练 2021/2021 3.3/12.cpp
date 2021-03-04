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
	cout<<(1<<31)<<endl;
	int i,j;
	int n;
	cin>>n;
	vector<int> val(1,100);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		cout<<a<<" ";
		for(j=0;j<val.size();j++){
			if(val[j]>=a) {val[j]-=a;break;}
		}
		if(j==val.size()){
			val.push_back(100-a);
		}
		cout<<j+1<<endl;
	}
	cout<<val.size()<<endl;
	return 0;
}