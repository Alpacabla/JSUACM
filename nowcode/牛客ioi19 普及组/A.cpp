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
const int max_n=5e6+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		string s[4];
		for(i=0;i<4;i++){
			cin>>s[i];
		}
		int min1=int_inf,ans;
		bool flag=false;
		for(i=0;i<4;i++){
			if(min1>s[i].size()){
				min1=s[i].size();
				flag=false;
				ans=i;
			}else{
				if(min1==s[i].size()){
					flag=true;
				}
			}
		}
		if(!flag){
			cout<<(char)('A'+ans)<<endl;
		}else{
			min1=-1;
			flag=false;
			for(i=0;i<4;i++){
				if(min1<(int)s[i].size()){
					min1=(int)s[i].size();
					flag=false;
					ans=i;
				}else{
					if(min1==s[i].size()){
						flag=true;
					}
				}
			}
			if(!flag){
				cout<<(char)('A'+ans)<<endl;
			}else{
				cout<<(char)('C')<<endl;
			}
		}
	}
	return 0;
}
