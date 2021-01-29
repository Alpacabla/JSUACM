#include<bits/stdc++.h>
#define _X(n) ((ll)(n)*(ll)(n))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x7f3f3f3f;
const ll ll_inf=0x7f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int a[max_n],b[max_n],c[max_n];
ll ans;
void solve(int a[],int a1,int b[],int b1,int c[],int c1)
{
	int i,j;
	int max1,k,t1=0;
	i=0,j=0;
	a1-=1,b1-=1,c1-=1;
	while(i!=a1||j!=b1){
		max1=max(a[i],b[j]);
		while(t1<c1&&c[t1]<max1){
			t1++;
		}
		k=c[t1];
		ans=min(ans,_X(a[i]-b[j])+_X(a[i]-k)+_X(b[j]-k));
		if(a[i+1]<b[j+1]) i++;
		else j++;
	}
	max1=max(a[i],b[j]);
	while(t1<c1&&c[t1]<max1){
		t1++;
	}
	k=c[t1];
	ans=min(ans,_X(a[i]-b[j])+_X(a[i]-k)+_X(b[j]-k));
	return ;
}
int main()
{
	int i,j,k;
	int t;
	int a1,b1,c1;
	cin>>t;
	while(t--){
		scanf("%d%d%d",&a1,&b1,&c1);
		for(i=0;i<a1;i++){
			scanf("%d",a+i);
		}
		for(i=0;i<b1;i++){
			scanf("%d",b+i);
		}
		for(i=0;i<c1;i++){
			scanf("%d",c+i);
		}
		sort(a,a+a1);
		sort(b,b+b1);
		sort(c,c+c1);
		a[a1]=b[b1]=c[c1]=int_inf;
		ans=ll_inf;
		solve(a,a1,b,b1,c,c1);
		solve(b,b1,c,c1,a,a1);
		solve(c,c1,a,a1,b,b1);
		printf("%lld\n",ans);
	}
	return 0;
}