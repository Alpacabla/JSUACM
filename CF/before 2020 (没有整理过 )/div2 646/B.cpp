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
	int n,x;
	cin>>t;
	while(t--){
		cin>>n>>x;
		int cnt1=0,cnt2=0;
		for(i=1;i<=n;i++){
			int num;
			cin>>num;
			if(num%2){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		if(cnt1==0){
			cout<<"No"<<endl;
		}else{
			if(cnt1%2==0){
				cnt1-=1;
			}
			int flag=0;
			for(i=1;i<=cnt1;i+=2){
				for(j=0;j<=cnt2;j++){
					if(x==i+j){
						flag=1;
					}
				}
			}
			if(flag) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}