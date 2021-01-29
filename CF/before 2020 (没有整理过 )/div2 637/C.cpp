#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int ind[max_n];
bool vis[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,t,num;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>num;
			ind[num]=i;
		}
		int flag=1,r;
		r=n;
		for(i=1;i<=n;i++){
			int now=ind[i];
			while(i<=n-1&&ind[i]+1==ind[i+1]){
				i++;
			}
			//if(!(i<=n-1)) break;
			if(ind[i]!=r){
				flag=0;
				break;
			} 
			r=now-1;
		}
		
		/*int i=2;
		int now=ind[1],r=n;
		int flag=1;
		//while()
		while(i<=n&&now==r){
			now=ind[i];
			r--;
			i++;
		}
		while(i<=n){
			if(ind[i]!=now+1){
				flag=0;
				break;
			}else{
				now=ind[i];
				i++;
				if(now==r){

				}
			}
		}*/
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}