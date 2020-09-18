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
	int n,s;
	cin>>n>>s;
	if(n==1&&s!=1){
		cout<<"YES"<<endl;
		cout<<s<<endl;
		cout<<1<<endl;
	}else{
		if(n==1&&s==1){
			cout<<"NO"<<endl;
		}else{
			if(2*n>s){
				cout<<"NO"<<endl;
			}else{
				cout<<"YES"<<endl;
				cout<<s-2*(n-1);
				for(i=1;i<n;i++){
					cout<<" "<<2;
				}
				cout<<endl;
				cout<<1<<endl;
			}
		}
	}
	
	return 0;
}