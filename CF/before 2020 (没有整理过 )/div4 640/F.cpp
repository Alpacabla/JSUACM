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
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	for(i=0;i<200;i++){
		s[i*2]='1';
		s[i*2+1]='0';
	}
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(b==0){
			int k=a?a:c;
			for(i=0;i<=k;i++){
				cout<<!(k==a);
			}
			cout<<endl;
			continue;
		}
		int cnt=0;
		for(i=0;cnt<b;i++){
			if(s[i]!=s[i+1]){
				cnt++;
			}
		}
		for(i=0;i<c;i++){
			cout<<1;
		}
		cout<<s[0];
		for(i=0;i<a;i++){
			cout<<0;
		}
		for(i=1;i<=cnt;i++){
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}