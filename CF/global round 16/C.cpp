// Problem: C. MAX-MEX Cut
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		bool flag1=false,flag2=false;
		for(int i=0;i<s1.size();i++){
			if(s1[i]<s2[i]) swap(s1[i],s2[i]);
			if(flag1||flag2){
				if(s1[i]=='1'&&s2[i]=='0'){
					ans+=2;
					ans+=flag1;
					flag1=flag2=false;
				}
				if(s1[i]=='0'&&s2[i]=='0'){
					if(flag1){
						ans++;
						flag1=flag2=false;
						flag1=true;
					}else{
						ans+=2;
						flag1=flag2=false;
					}
				}
				if(s1[i]=='1'&&s2[i]=='1'){
					if(flag1) {flag1=flag2=false;ans+=2;}
					else{
						flag1=flag2=false;
						flag2=true;
					}
				}
			}else{
				if(s1[i]=='0'&&s2[i]=='0'){
					flag1=true;
				}
				if(s1[i]=='1'&&s2[i]=='0'){
					ans+=2;
				}
				if(s1[i]=='1'&&s2[i]=='1'){
					flag2=true;
				}
			}
		}
		cout<<ans+flag1<<endl;
	}
	return 0;
}