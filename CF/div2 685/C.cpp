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
int cnt2[150],cnt1[150];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		string s1,s2;
		cin>>s1>>s2;
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(int i=0;i<n;i++){
			cnt1[s1[i]]++;
			cnt2[s2[i]]++;
		}
		bool flag=true;
		for(int ch='a';ch<='z';ch++){
			if(ch=='z'){
				flag=(cnt1[ch]==cnt2[ch]);
				break;
			}
			if(cnt2[ch]>cnt1[ch]){
				flag=false;
				break;
			}else{
				if((cnt1[ch]-cnt2[ch])%m!=0){
					flag=false;
					break;
				}
				cnt1[ch+1]+=(cnt1[ch]-cnt2[ch]);
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}