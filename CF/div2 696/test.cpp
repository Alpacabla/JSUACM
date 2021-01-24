#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;

const int N=2e+5+10;
long long int a[N],n,sd[N],mini[2][N],fmini[N];
namespace aaa{
	bool solve()
	{
		int i,j;
		vector<ll> num(n+2),d(n+2);
		for(int i=1;i<=n;i++){
			num[i]=a[i];
		}

		bool flag=true;
		num[n+1]=0;
		for(int i=1;i<=n+1;i++){
			d[i]=num[i]-d[i-1];
			if(d[i]<0) flag=false;
		}
		if(flag){
			return 1;
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
		// if(cnt>=2){
		// 	return 0;
		// }

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
			return 0;
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
			if(flag) return 1;
			else return 0;
		}
	}
}
bool ispos(long long int d,int i)
{
	if(i==n)
		return sd[n]==-d;
	if(mini[i%2][i]<-d||mini[1-i%2][i]<d)
		return false;
	long long int j=-1;
	if(i%2!=n%2)
		j=1;
	if(sd[n]!=d*j)
		return false;
	return true;
}
int main()
{
	srand(time(0));
	while(1)
	{
		n=6;
		//cin>>n;
		fmini[0]=1e+16;
		for(int i=1;i<=n;i++)
		{
			//cin>>a[i];
			a[i]=rand()%10;
			sd[i]=a[i]-sd[i-1];
			fmini[i]=min(fmini[i-1],sd[i]);
			//cout<<sd[i]<<"\n";
		}
		a[n+1]=0;
		mini[n%2][n]=sd[n];
		mini[1-n%2][n]=1e+16;
		for(int i=n-1;i>=0;i--)
		{
			mini[0][i]=mini[0][i+1];
			mini[1][i]=mini[1][i+1];
			if(i>0)
			{
				mini[i%2][i]=min(sd[i],mini[i%2][i]);
			}
		}
		string ans="NO";
		if(fmini[n]>=0&&sd[n]==0)
			ans="YES";
		for(int i=1;i<n;i++)
		{
			if(ispos(2LL*(a[i]-a[i+1]),i+1)&&sd[i]+a[i+1]>=a[i]&&fmini[i-1]>=0)
			{
				ans="YES";
			}
		}
		bool flag=(ans=="YES");
		if(flag!=aaa::solve()){
			for(int i=1;i<=n;i++){
				cout<<a[i]<<endl;
			}
			int k;
			cin>>k;
		}
		if(flag) cout<<"y"<<endl;
		else cout<<"n"<<endl;
	}
}


