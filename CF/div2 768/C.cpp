// Problem: C. And Matching
// Contest: Codeforces - Codeforces Round #768 (Div. 2)
// URL: https://codeforces.com/contest/1631/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> vis(n);
		if(n-1==k){
			if(k==3){
				cout<<"-1"<<endl;
			}else{
				int ans=0;
				n-=1;
				cout<<n<<" "<<n-1<<endl;
				ans+=n&(n-1);
				cout<<1<<" "<<n-2<<endl;
				cout<<2<<" "<<0<<endl;
				ans+=1&(n-2);
				
				vis[n]=vis[n-1]=vis[1]=vis[n-2]=vis[2]=vis[0]=true;
				n+=1;
				for(int i=0;i<n;i++){
					if(!vis[i]) {
						vis[i]=true;
						vis[((~i)&(n-1))]=true;
						cout<<i<<" "<<((~i)&(n-1))<<endl;
						ans+=(i)&((~i)&(n-1));
					}
				}
				// if(ans!=k){
					// cout<<"no"<<endl;
				// }
			}
		}else{
			int ans=0;
			if(k!=0){
				cout<<n-1<<" "<<k<<endl;
				ans+=(n-1)&k;
				
				cout<<((~k)&(n-1))<<" "<<0<<endl;
				
				vis[n-1]=vis[k]=vis[(~k)&(n-1)]=vis[0]=true;
			}
			for(int i=0;i<n;i++){
				if(!vis[i]) {
					vis[i]=true;
					vis[((~i)&(n-1))]=true;
					cout<<i<<" "<<((~i)&(n-1))<<endl;
					ans+=(i)&((~i)&(n-1));
				}
			}
			if(ans!=k){
				cout<<"no"<<endl;
			}
		}
	}
	
	return 0;
}