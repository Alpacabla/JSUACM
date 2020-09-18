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
bool vis[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis,0,103);
		int a=0,b=0;
		for(i=1;i<=n;i++){
			int k;
			cin>>k;
			vis[k]=1;
			if(k%2){
				a++;
			}else{
				b++;
			}
		}
		int flag=1;
		if(a%2==0&&b%2==0){
			flag=1;
		}else{
			if(a%2==1&&b%2==1){
				for(i=2;i<=100;i++){
					if(vis[i]&&vis[i-1]){
						break;
					}
				}
				if(i==101){
					flag=0;
				}else flag=1;
			}else{
				flag=0;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}