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
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m=n;
		n*=2;
		vector<ll> num(n+1);
		ll min1=ll_inf;
		for(int i=1;i<=n;i++){
			cin>>num[i];
			if(num[i]>0){
				min1=min(min1,num[i]);
			}
		}
		map<ll,int> mp;
		bool flag=true;
		for(int i=1;i<=n;i++){
			mp[num[i]]++;
			if(mp[num[i]]>2){
				flag=false;
				break;
			}
		}
		if(flag){
			ll i=0;
			ll sum=0;
			ll last=-1;
			ll now=0;
			for(auto a:mp){
				if(i==0){
					now=1;
					sum+=now;
					last=a.first;
				}else{
					ll d=(a.first)-last;
					if(d%i!=0){
						flag=false;
						break;
					}else{
						now=now+d/i;
						sum+=now;
					}
					last=a.first;
				}
				i+=2;
			}
			sum*=2;
			if(sum>min1){
				flag=false;
			}else{
				if((min1-sum)%n!=0){
					flag=false;
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}