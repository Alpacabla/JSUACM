#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
bool vis[max_n];
int l[max_n];
int r[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	ll ans;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>num[i].v;
		num[i].ind=i;
		l[i]=i-1;
		if(i==1){
			l[i]=n;
		}
		r[i]=i+1;
		if(i==n){
			r[i]=1;
		}
		q.push(num[i]);
	}
	int cnt=0;
	while(!q.empty()){
		node temp=q.top();
		q.pop();
		bool flag=true;
		if(!vis[temp.ind%n]){
			if(cnt==n-1){
				ans=num[temp.ind].v;
				flag=false;
			}
			int le,ri;
			le=l[temp.ind];
			//if(le==0){
			//	le=l[n];
			//}
			ri=r[temp.ind];
			//if(ri==n+1){
			//	ri=r[1];
			//}
			l[temp.ind]=l[le];
			r[temp.ind]=r[ri];
			l[r[ri]]=temp.ind;
			r[l[le]]=temp.ind;
			num[temp.ind].v=num[le].v+num[ri].v;
			vis[le%n]=true;
			vis[ri%n]=true;
			cnt+=2;
			//cout<<le<<" "<<ri<<endl;;

			q.push(num[temp.ind]);
			
		}
		if(!flag) break;
	}
	cout<<ans<<endl;
	return 0;
}