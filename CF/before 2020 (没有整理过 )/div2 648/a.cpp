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
int book[55][55];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>book[i][j];
			}
		}
		int cnt1=0,cnt2=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(book[i][j]==1){
					break;
				}
			}
			if(j>m) cnt1++;
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(book[j][i]==1){
					break;
				}
			}
			if(j>n) cnt2++;
		}
		int min1=min(cnt1,cnt2);
		if(min1%2){
			cout<<"Ashish"<<endl;
		}else{
			cout<<"Vivek"<<endl;
		}
	}
	return 0;
}