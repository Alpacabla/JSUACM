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
const int max_n=2e5+5;
int cnt[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n,num;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++){
			cin>>num;
			cnt[num]++;
		}
		int ans=-1,dif=0;
		for(i=1;i<=n;i++){
			if(cnt[i]){
				dif++;
				ans=max(ans,cnt[i]);
			}
		}
		cout<<max(min(dif,ans-1),min(dif-1,ans))<<endl;
	}
	return 0;
}