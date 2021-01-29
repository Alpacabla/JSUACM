#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
char s[2500];
int main()
{
	int i,j;
	int n,a,b;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		int d=a-b;
		int cnt=0;
		for(i=0;i<=d;i++){
			s[i]='a';
		}
		cnt=i;
		for(i=1;i<b;i++){
			s[cnt++]='a'+i;
		}
		s[cnt]='\0';
		while(n>=a){
			printf("%s",s);
			n-=a;
		}
		i=0;
		while(n){
			putchar(s[i]);
			i++;
			n--;
		}
		putchar(10);
	}
	return 0;
}