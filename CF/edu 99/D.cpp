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
bool judge(vector<int> &num)
{
	for(int i=1;i<num.size();i++){
		if(num[i]<num[i-1]) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> num(n);
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		int ans=0;
		int now=0;
		while(!judge(num)){
			ans++;
			bool flag=true;
			for(int i=now;i<n;i++){
				if(num[i]>m){
					swap(num[i],m);
					now=i+1;
					flag=false;
					break;
				}
			}
			if(flag) break;
		}
		if(judge(num)) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}