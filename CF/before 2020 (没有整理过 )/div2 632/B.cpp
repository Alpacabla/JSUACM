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
int a[max_n],b[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int f1=1,f2=1;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		for(i=0;i<n;i++){
			cin>>b[i];
		}
		for(i=n-1;i>=0;i--){
			if(a[i]==-1){
				f2=1;
			}
			if(a[i]==1){
				f1=1;
			}
			if(a[i]<b[i]){
				f1=0;
			}
			if(a[i]>b[i]){
				f2=0;
			}
		}
		if(f1&&f2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}