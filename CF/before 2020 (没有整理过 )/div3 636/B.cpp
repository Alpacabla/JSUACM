#include<bits/stdc++.h>
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
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%4==0){
			cout<<"YES"<<endl;
			for(i=2;i<=n;i+=2){
				cout<<i<<" ";
			}
			for(i=1;i<n-2;i+=2){
				cout<<i<<" ";
			}
			cout<<i+n/2<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}