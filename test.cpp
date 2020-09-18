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
char s[max_n];
int xx[10];
char res[max_n];
void init(const int n)
{
	for(int i=1;i<=9;i++){
		xx[n*i%10]=i;
	}
	xx[0]=0;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	while(cin>>n){
		if(n==1){
			cout<<1<<" "<<1<<endl;
			continue;
		}
		init(n);
		int tot=0;
		int last=10;
		int max1=0;
		i=0;
		int k=0;
		while(1){
			if(i>max1) break;
			int a=xx[(11-last)%10];
			s[tot++]=a+'0';
			int t=n;
			j=i;
			if(a!=0){
				k=i;
				int jin=0;
				while(t){
					res[j]+=a*(t%10)+jin;
					jin=res[j]/10;
					res[j]%=10;
					t/=10;
					j++;
				}
				res[j]+=jin;
				while(res[j]>10){
					res[j+1]+=res[j]/10;
					res[j]%=10;
					j++;
				}
				max1=max(j,max1);
			}
			last=res[++i];
		}
		s[tot++]='\0';
		for(i=k;i>=0;ei--){
			cout<<s[i];
		}
		for(i=0;i<max1+5;i++){
			res[i]=0;
		}
		cout<<" "<<max1+1<<endl;
	}
	
	return 0;
}
