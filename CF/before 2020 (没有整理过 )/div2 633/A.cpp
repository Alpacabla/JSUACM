#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int a,b;
	int a1,b1;
	int t,n;
	cin>>t;
	a1=b1=0;
	while(t--){
		cin>>n;
		int flag=1;
		a1=b1=0;
		while(n--){
			cin>>a>>b;
			if(a>=a1&&b>=b1&&b-b1<=a-a1&&a>=b){
			}else flag=0;
			a1=a;b1=b;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}