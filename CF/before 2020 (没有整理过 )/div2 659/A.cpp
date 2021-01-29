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
int num[105];
string s[105];
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
		int max1=-1;
		for(i=1;i<=n;i++){
			cin>>num[i];
			max1=max(max1,num[i]);
		}
		max1+=1;
		for(i=0;i<=n;i++){
			s[i].resize(max1);
		}
		for(i=0;i<max1;i++){
			s[0][i]=(rand()%26)+'a';
		}
		for(i=1;i<=n;i++){
			s[i]=s[i-1];
			for(j=num[i];j<max1;j++){
				while(s[i][j]==s[i-1][j]){
					s[i][j]=(rand()%26)+'a';
				}
			}
		}
		for(i=0;i<=n;i++){
			cout<<s[i]<<endl;
		}
	}
	return 0;
}