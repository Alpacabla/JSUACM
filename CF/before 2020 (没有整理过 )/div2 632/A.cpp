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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,t;
	int i,j;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=0;i<n-1;i++){
			for(j=0;j<m;j++){
				cout<<'B';
			}
			cout<<endl;
		}
		for(j=0;j<m-1;j++){
			cout<<'B';
		}
		cout<<'W'<<endl;
	}

	return 0;
}