#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=3e5+5;
ll d[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		ll n,k,l;
		cin>>n>>k>>l;
		for(i=1;i<=n;i++){
			cin>>d[i];
		}
		bool flag=true;
		ll l1=-min(l-d[1],k);
		ll l2=-l1;
		if(l-d[1]<0){
			cout<<"No"<<endl;
			continue;
		}
		for(i=2;i<=n;i++){
			ll n1,n2;
			//cout<<l1<<" "<<l2<<endl;
			if(l2-l1!=2*k){
				l1+=1;
				l2+=1;
			}
			if(l-d[i]<0){
				flag=false;
				break;
			}
			n1=-min((l-d[i]),k);
			n2=-n1;
			//cout<<n1<<" "<<n2<<endl;
			if(n2<l1||n1>l2){
				flag=false;
				break;
			}
			if(n2-n1!=2*k) n1=max(n1,l1);
			
			//n1=max(-k,n1);
			//n2=min(k,n2);
			l1=n1;
			l2=n2;
			if(l1>l2){
				flag=false;
				//cout<<"###########"<<endl;
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}