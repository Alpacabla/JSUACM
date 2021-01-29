#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e6+5;
int bit[max_n];
int book[max_n];
int d[max_n];
int n;
void update(int ind,int num)
{
	while(ind<=n){
		bit[ind]+=num;
		ind+=lowbit(ind);
	}
	return ;
}
void init()
{
	int i;
	for(i=1;i<=n;i++){
		update(i,d[i]);
	}
}

int query(int ind)
{
	int res=0;
	while(ind>0){
		res+=bit[ind];
		ind-=lowbit(ind);
	}
	return res;
}
int main()
{
	int i,j;
	int q;
	int num;
	cin>>n>>q;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		book[num]++;
	}
	for(i=1;i<=n;i++){
		book[i]+=book[i-1];
		//cout<<book[i]<<endl;
	}
	for(i=1;i<=n;i++){
		d[i]=book[i]-book[i-1];
	}
	init();
	for(i=0;i<q;i++){
		int k;
		scanf("%d",&k);
		if(k<0){
			k=-k;
			int l=1,r=n;
			int res;
			while(l<=r){
				int mid=(l+r)>>1;
				if(query(mid)>=k){
					res=mid;
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			update(res,-1);
		}else{
			update(k,1);
			//update(k+1,-1);
		}
	}
	for(i=1;i<=n;i++){
		int k=query(i);
		if(k!=0){
			cout<<i<<endl;
			exit(0);
		}
		//cout<<k<<endl;
		//while(k--){
		//	printf("%d ",i);
		//}
	}
	cout<<0<<endl;
	return 0;
}