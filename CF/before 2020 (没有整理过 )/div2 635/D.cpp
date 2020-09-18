#include<bits/stdc++.h>
#define _X(n) ((ll)(n)*(ll)(n))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x7f3f3f3f;
const ll ll_inf=0x7f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int a[max_n],b[max_n],c[max_n];
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
		a[a1]=b[b1]=c[c1]=a[a1+1]=b[b1+1]=c[c1+1]=int_inf;
		//int sum=a1+b1+c1;
		//a1-=1;b1-=1;c1-=1;
		ll ans=ll_inf;
		int t1,t2,t3;
		for(i=0,j=0,k=0;!(i==a1&&j==b1&&k==c1);){
			if(i==a1) t1=a[i-1];
			else t1=a[i];
			if(j==b1) t2=b[j-1];
			else t2=b[j];
			if(k==c1) t3=c[k-1];
			else t3=c[k];
			ans=min(ans,(ll)_X(t1-t2)+_X(t2-t3)+_X(t1-t3));
			//ans=min(ans,_X(a[i]-b[j])+_X(a[i]-c[k])+_X(b[j]-c[k]));
			if(a[i]<=b[j]&&a[i]<=c[k]&&i!=a1){
				if(a[i]==b[j]){
					if(a[i+1]<=b[j+1]){
						i++;
					}else{
						j++;
					}
				}else{
					if(a[i]==c[k]){
						if(a[i+1]<=c[k+1]){
							i++;
						}else{
							k++;
						}
					}else i++;
				}
			}else{
				if(b[j]<=a[i]&&b[j]<=c[k]&&j!=b1){
					if(a[i]==b[j]){
						if(a[i+1]=b[j+1]){
							i++;
						}else{
							j++;
						}
					}else{
						if(b[j]==c[k]){
							if(b[j+1]<=c[k+1]){
								j++;
							}else{
								k++;
							}
						}else j++;
					}
				}else{
				if(c[k]<=b[j]&&a[i]>=c[k]&&k!=c1){
					if(c[k]==b[j]){
						if(c[k+1]<=b[j+1]){
							k++;
						}else{
							j++;
						}
					}else{
						if(a[i]==c[k]){
							if(a[i+1]<c[k+1]){
								i++;
							}else{
								k++;
							}
						}else k++;
					}
				}
				
			}
			}
			
			//printf("%d%d%d\n",i,j,k);
		}
		printf("%lld\n",ans);
	}
	return 0;
}