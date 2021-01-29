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
struct nodes{
	int l,r;
	int len;
	bool operator < (const nodes &a) const {
		if(len==a.len){
			return l>a.l;
		}else{
			return len<a.len;
		}
	}
};
int ans[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n;
		memset(ans,0,(n+3)*sizeof(int));
		priority_queue<nodes>q;
		q.push((nodes){1,n,n});
		for(i=1;i<=n;i++){
			nodes t=q.top();
			//cout<<t.l<<" "<<t.r<<" "<<endl;
			q.pop();
			int mid=(t.l+t.r)/2;
			ans[mid]=i;
			if(t.l!=mid){
				q.push((nodes){t.l,mid-1,mid-1-t.l+1});
			}
			if(mid!=t.r){
				q.push((nodes){mid+1,t.r,t.r-(mid+1)+1});
			}
		}
		for(i=1;i<=n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}