// Problem: B. TMT Document
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int sum=0;
		int cnt=0;
		bool flag=true;
		for(int i=0;i<n;i++){
			sum+=(s[i]=='T')?1:-1;
			if(sum<0) flag=false;
			cnt+=s[i]=='M';
		}
		if(sum!=cnt) flag=false;
		sum=0;
		cnt=0;
		for(int i=n-1;i>=0;i--){
			sum+=(s[i]=='T')?1:-1;
			if(sum<0) flag=false;
			cnt+=s[i]=='M';
		}
		if(sum!=cnt) flag=false;
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		//vector<bool> vis(n+1);
		// int r=n-1;
		// int cnt=0;
		// bool flag=true;
		// for(int i=0;i<n&&flag;i++){
			// if(!vis[i]){
				// if(s[i]=='T'){
					// while(r>=0&&s[r]!='T'&&!vis[r]) r--;
					// if(r<0||r<=i){
						// flag=false;
						// continue;
					// }
					// vis[r]=true;
					// vis[i]=true;
					// cnt++;
				// }else{
					// vis[i]=true;
					// cnt--;
					// if(cnt<0){
						// flag=false;
					// }
				// }
			// }
		// }
	}
	return 0;
}