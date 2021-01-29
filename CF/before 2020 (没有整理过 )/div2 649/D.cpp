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
int x[2055][2055];
int ans[2055];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(i=1;i<n;i++){
		cout<<"? "<<i<<" "<<i+1<<endl;
		cout.flush();
		cin>>x[i][i+1];
		x[i+1][i]=x[i][i+1];
	}
	for(i=1;i<n-1;i++){
		for(j=i+2;j<=n;j++){
			cout<<i<<" "<<j<<endl;
			x[i][j]=x[i][j-1]^x[j-1][j];
			cout<<x[i][j]<<endl;
			x[j][i]=x[i][j];
		}
	}
	cout<<x[1][2]<<" "<<x[1][3]<<" "<<endl;
	for(i=0;i<n;i++){
		cout<<"i"<<endl;
		cout<<i<<endl;

		ans[1]=i;
		for(j=2;j<=n;j++){
			ans[j]=ans[1]^x[1][j];
			cout<<ans[j]<<endl;
		}
		int flag=1;
		int k;
		for(k=2;k<=n&&flag;k++){
			for(j=k+1;j<=n;j++){
				if(x[k][j]!=(ans[k]^ans[j])){
					flag=0;
					break;
				}
			}
		}
		if(flag) break;
	}
	cout.flush();
	cout<<"! ";
	for(i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}