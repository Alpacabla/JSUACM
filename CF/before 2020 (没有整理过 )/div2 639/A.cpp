#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int num[max_n];
bool vis[max_n];
inline int mod(int a,int b){
	return (b-abs(a)%b)%b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis,0,n+1);
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		int k;
		for(i=0;i<n;i++){
			if(i+num[i]>=0){
				k=abs(i+num[i])%n;
			}else{
				k=mod(i+num[i],n);
			}
			if(vis[k]){
				break;
			}else vis[k]=true;
		}
		if(i==n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}