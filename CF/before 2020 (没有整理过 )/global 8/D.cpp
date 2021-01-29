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
	int n;
	int num;
	int cnt[21]={0};
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num;
		int k=0;
		while(num){
			if(num&1){
				cnt[k]++;
			}
			num>>=1;
			k++;
		}
	}
	ull ans=0;
	for(i=0;i<n;i++){
		ull now=0;
		for(j=0;j<=20;j++){
			if(cnt[j]){
				now+=(1<<j);
				cnt[j]--;
			}
		}
		ans+=now*now;
	}
	cout<<ans<<endl;
	return 0;
}