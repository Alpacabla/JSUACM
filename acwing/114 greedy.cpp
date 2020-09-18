/*
link: https://www.acwing.com/problem/content/116/
tags: greedy 大数乘法
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
const int max_n=4e6+5;
int a[1005],b[1005],ind[1005];
int s[max_n];
int len;
void mul(int num)
{
	int i;
	for(i=0;i<len;i++){
		s[i]*=num;
	}
	for(i=0;i<len||s[i]>0;i++){
		s[i+1]+=s[i]/10;
		s[i]%=10;
	}
	len=i;
	return ;
}
string div(int num)
{
	int flag=0;
	int k=0;
	string res="";
	for(int i=len-1;i>=0;i--){
		k=k*10+s[i];
		if(flag||k>=num){
			res+=(char)(k/num+48);
			flag=true;
		}
		k%=num;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	int last;
	cin>>n;
	cin>>last>>i;
	for(i=0;i<n;i++){
		cin>>a[i]>>b[i];
		ind[i]=i;
	}
	sort(ind,ind+n,[](int x,int y) -> bool{ 
		return a[x]*b[x]<a[y]*b[y];
	});
	string max1="";
	len=1;
	s[0]=last;
	for(i=0;i<n;i++){
		string res=div(b[ind[i]]);
		if(max1.size()==res.size()){
			if(max1<res) max1=res;
		}else{
			if(max1.size()<res.size()){
				max1=res;
			}
		}
		mul(a[ind[i]]);
	}
	cout<<max1<<endl;
	return 0;
}
