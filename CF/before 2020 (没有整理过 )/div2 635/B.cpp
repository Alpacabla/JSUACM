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
	int num;
	cin>>t;
	while(t--){
		int m,k;
		cin>>num>>m>>k;
		while(num>20&&m){
			num/=2;
			num+=10;
			m--;
		}
		num-=10*k;
		if(num<=0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}