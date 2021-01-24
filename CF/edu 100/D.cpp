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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> num(n+2);
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		vector<int> dp1(n+2),dp2(n+2);
		int now=1;
		int cnt=0;
		int l=0,r=0;
		i=1;
		while(now<=2*n&&i<=n){
			if(now==num[i]){
				if(cnt>0) l++,cnt--;
				i++;
			}else{
				cnt++;
			}
			now++;
		}

		cnt=0;
		now=2*n;
		i=n;
		while(now>=1&&i>=1){
			if(now==num[i]){
				if(cnt>0) r++,cnt--;
				i--;
			}else{
				cnt++;
			}
			now--;
		}

		r=n-r;
		cout<<max(0,l-r+1)<<endl;
	}
	return 0;
}