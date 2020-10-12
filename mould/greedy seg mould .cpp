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
int mins[2505],maxs[2505];
int cnt[1005];
int ind[2505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>mins[i]>>maxs[i];
		ind[i]=i;
	}
	for(i=0;i<m;i++){
		int spf,c;
		cin>>spf>>c;
		cnt[spf]+=c;
	}
	sort(ind,ind+n,[](int a,int b) -> bool{ 
		if(maxs[a]==maxs[b]) return mins[a]<mins[b];
		else return maxs[a]<maxs[b];
	});
	int ans=0;
	for(i=0;i<n;i++){
		for(j=mins[ind[i]];j<=maxs[ind[i]];j++){
			if(cnt[j]>0){
				cnt[j]--;
				ans++;
				break;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}