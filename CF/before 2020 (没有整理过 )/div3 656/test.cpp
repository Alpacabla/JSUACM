#include <bits/stdc++.h>
using namespace std;
char s[200010];
int solve(int l,int r,int c) {
	int mid = l+r>>1;
	if(l == r) return s[l] !=(c+'a');
	int cnt = 0;
	for(int i=l;i<=mid;i++) {
		if(s[i] != c+'a') {
			cnt++;
		}
	}
	int ans = 1e9;
	ans = min(ans,cnt+solve(mid+1,r,c+1));
	cnt = 0;
	for(int i=mid+1;i<=r;i++) {
		if(s[i]!= c+'a') {
			cnt++;
		}
	}
	ans = min(ans,cnt+solve(l,mid,c+1));
	return ans;
}
int main()
{
	int t;
	//cin>>t;
	t=1;

	while(t--) {
		int n;
		n=131072;
		//cout<<3*n<<endl;
		//cin>>n;
		for(int i=1;i<=131072;i++){
			s[i]='a';
		}
		cout<<solve(1,n,0)<<endl;
	}
}
