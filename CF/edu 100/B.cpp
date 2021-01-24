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
	int num[32]={0};
	int lim;
	for(int i=0;i<31;i++){
		num[i]=(1<<i);
		if((num[i])>=1e9){
			lim=i-1;
			break;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			int k=lower_bound(num,num+lim+1,a)-num;
			if(k==0) cout<<num[k]<<" ";
			else cout<<num[k-1]<<" ";
		}
		cout<<endl;
	}
	return 0;
}