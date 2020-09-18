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
int num[1025];
int book[5000];
int book1[5000];
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
		memset(book,0,sizeof(book));
		for(i=0;i<n;i++){
			cin>>num[i];
			book[num[i]]++;
		}
		int flag=0;
		for(i=1;i<=2048;i++){
			memset(book1,0,sizeof(book1));
			for(j=0;j<n;j++){
				book1[num[j]^i]++;
			}
			for(j=0;j<5000;j++){
				if(book[j]!=book1[j]) break;
			}
			if(j==5000){
				flag=1;
				break;
			}
		}
		if(flag) cout<<i<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}