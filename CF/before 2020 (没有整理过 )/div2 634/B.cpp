#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
int num[100005];
int ans[100005];
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
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		sort(num,num+n);
		int r=n-1,l=0;
		int flag=1;
		for(i=n-1;i>=0;i--){
			if(flag) ans[i]=num[r],--r,flag=0;
			else ans[i]=num[l],++l,flag=1;
		}
		for(i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}