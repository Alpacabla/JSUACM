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
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int sum=0;
		for(i=1;i<=n;i++){
			cin>>num[i];
			sum+=num[i];
		}
		if(sum%m!=0){
			cout<<n<<endl;
		}else{
			for(i=1;i<=n;i++){
				if(num[i]%m!=0){
					break;
				}
			}
			for(j=n;j>=1;j--){
				if(num[j]%m!=0){
					break;
				}
			}
			if(i!=n+1&&j!=0){
				int k;
				if(i==n+1){
					k=n-j+1;
				}else{
					if(j==0){
						k=i;
					}else{
						k=min(i,n-j+1);
					}
				}
				cout<<n-k<<endl;
			}else{
				cout<<-1<<endl;
			}
			
		}
	}
	return 0;
}