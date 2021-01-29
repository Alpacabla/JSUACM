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
	int t,n;
	int a,b,c,d;
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>c>>d;
		int x1=(a-b)*n,x2=(a+b)*n;
		int y1=c-d,y2=c+d;
		if(y1>x2||y2<x1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}