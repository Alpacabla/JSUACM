#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> aa(n);
	int ans=0;
	int cnt=0;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		aa[i]=c;
		if(c==1) cnt++;
		ans+=c;
	}
	sort(aa.begin()+1,aa.end());
	if(cnt==n-1){
		cout<<-1<<endl;
	}else{
		cout<<ans+1<<endl;
	}
	return 0;
}