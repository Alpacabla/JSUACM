// Problem: 音乐家的曲调
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11175/B
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int max_n=1e7+5;
int cnt[26];
char s[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> rr(n+1);
	cin>>(s+1);
	bool flag=true;
	for(int l=1,r=0;l<=n;l++){
		while(flag&&(r<=n&&++cnt[s[++r]]<=m)){
		}
		rr[l]=r-1;
		--cnt[s[l]];
		if(cnt[s[r-1]]>m) flag=false;
		else flag=true;
	}
	vector<int> max1(n+2);
	for(int i=n;i>=1;i--){
		max1[i]=max(max1[i+1],(rr[i]-i+1));
	}
	vector<int> max2(n+2);
	for(int i=n;i>=1;i--){
		max2[i]=max(max2[i+1],(rr[i]-i+1)+max1[rr[i]+1]);
	}
	vector<int> max3(n+2);
	for(int i=n;i>=1;i--){
		max3[i]=max(max3[i+1],(rr[i]-i+1)+max2[rr[i]+1]);
	}
	cout<<max3[1]<<endl;
	return 0;
}