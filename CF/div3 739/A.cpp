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
bool check(int a)
{
	while(a){
		if(a%10==3) return true;
		a/=10;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	vector<int> ans(1001);
	int now=0;
	for(int i=1;i<=1000;i++){
		while(now%3==0||(now)%10==3){
			now++;
		}
		ans[i]=now;
		now++;
	}
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		cout<<ans[k]<<endl;
	}
	return 0;
}