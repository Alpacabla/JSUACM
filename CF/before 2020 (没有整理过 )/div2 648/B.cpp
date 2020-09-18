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
int num[515];
int type[515];
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
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		for(i=0;i<n;i++){
			cin>>type[i];
		}
		int flag=0;
		for(i=0;i<n;i++){
			if(type[i]==1) break;
		}
		if(i==n) flag=1;
		for(i=0;i<n;i++){
			if(type[i]==0) break;
		}
		if(i==n) flag=1;
		if(flag){
			for(i=0;i<n-1;i++){
				if(num[i]>num[i+1]){
					break;
				}
			}
			if(i>=n-1){
				flag=0;
			}
		}
		if(flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}