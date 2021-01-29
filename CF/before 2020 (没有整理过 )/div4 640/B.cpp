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
	int n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int flag=1;
		if(n%2){
			if(n<m||m%2==0){
				flag=0;
			}else{
				cout<<"YES"<<endl;
				cout<<n-m+1<<" ";
				for(i=1;i<=m-1;i++){
					cout<<1<<" ";
				}
				cout<<endl;
			}
		}else{
			if(m%2){
				if(n<m*2){
					flag=0;
				}else{
					cout<<"YES"<<endl;
					cout<<n-(m-1)*2<<" ";
					for(i=1;i<=m-1;i++){
						cout<<2<<" ";
					}
					cout<<endl;
				}
			}else{
				if(n<m){
					flag=0;
				}else{
					cout<<"YES"<<endl;
					cout<<n-m+1<<" ";
					for(i=1;i<=m-1;i++){
						cout<<1<<" ";
					}
					cout<<endl;
				}
			}
			
		}

		if(!flag) cout<<"NO"<<endl;
	}
	return 0;
}