#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
const int max_n=5e4+5;
char a[max_n];
char b[max_n];
char x[max_n];
int main()
{
	int t;
	int i;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,&x);
		int len=n;
		int flag=1;
		a[0]=b[0]='1';
		for(i=1;i<len;i++){
			if(flag){
				if(x[i]=='2'){
					a[i]='1';
					b[i]='1';
				}
				if(x[i]=='1'){
					a[i]='1';
					b[i]='0';
					flag=0;
				}
				if(x[i]=='0'){
					a[i]='0';
					b[i]='0';
				}
			}else{
				if(x[i]=='2'){
					a[i]='0';
					b[i]='2';
				}
				if(x[i]=='1'){
					a[i]='0';
					b[i]='1';
				}
				if(x[i]=='0'){
					a[i]='0';
					b[i]='0';
				}
			}
		}
		a[n]=0;
		b[n]=0;
		printf("%s\n%s\n",a,b);
	}
	return 0;
}