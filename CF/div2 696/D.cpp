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
		vector<ll> num(n+2),d(n+2);
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}

		bool flag=true;
		num[n+1]=0;
		for(int i=1;i<=n+1;i++){
			d[i]=num[i]-d[i-1];
			if(d[i]<0) flag=false;
		}
		if(flag){
			cout<<"YES"<<endl;
			flag=true;
			continue;
		}
		flag=true;

		ll min1=ll_inf;
		ll last=1;
		int start=-1;
		int cnt=0;

		for(int i=1;i<=n+1;i+=2){
			if(d[i]<0){
				if(cnt==0) cnt++;
				if(last==1) start=i;
				min1=min(min1,d[i]);
				last=d[i];
			}
		}

		for(int i=2;i<=n+1;i+=2){
			if(d[i]<0){
				if(cnt==1) cnt++;
			}
		}
		if(cnt>=2){
			cout<<"NO"<<endl;
			continue;
		}

		if(last==1){
			for(int i=2;i<=n+1;i+=2){
				if(d[i]<0){
					if(last==1) start=i;
					min1=min(min1,d[i]);
					last=d[i];
				}
			}
		}
		if(last!=min1){
			flag=false;
		}
		if(!flag){
			cout<<"NO"<<endl;
		}else{
			ll minn=ll_inf;
			for(int i=start+1;i<=n+1;i+=2){
				minn=min(minn,d[i]);
			}
			if(minn<abs(min1)){
				flag=false;
			}
			if(flag){
				int j=0;
				for(i=start;i>=1;i--){
					if(i<n){
						if(d[i]+(num[i+1]-num[i])>=0){
							if(j%2==0){
								if((num[i+1]-num[i])*2==abs(min1)){
									flag=true;
									break;
								}
							}else{
								if((num[i+1]-num[i])*2==min1){
									flag=true;
									break;
								}
							}
						}
					}
					if(j%2==1){
						minn=min(minn,d[i]);
					}
					if(minn<abs(min1)){
						i=0;
						break;
					}
					j++;
				}
				if(i==0) flag=false;
			}
			if(flag) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}