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
bool vis[100];
void init(int d)
{
	memset(vis,0,sizeof(vis));
	int lim=d*10;
	vector<int> dd;
	dd.push_back(d);
	vis[d]=true;
	for(int i=1;i<=lim;i++){
		int a=i;
		bool flag=false;
		while(a){
			int k=(a%10);
			if(k==d){
				flag=true;
				break;
			}
			a/=10;
		}
		if(flag){
			vis[i]=true;
			dd.push_back(d);
			for(int j=0;j<dd.size();j++){
				int sum=dd[j]+i;
				if(sum<lim){
					if(!vis[sum]){
						vis[sum]=true;
						dd.push_back(sum);
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int q,d;
		cin>>q>>d;
		init(d);
		int lim=d*10;
		for(int i=0;i<q;i++){
			int a;
			cin>>a;
			if(a>=lim){
				cout<<"YES"<<endl;
			}else{
				if(vis[a]) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}