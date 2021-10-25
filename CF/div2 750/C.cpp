// Problem: C. Grandma Capa Knits a Scarf
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		int ans=int_inf;
		for(int i='a';i<='z';i++){
			int l=0,r=n-1;
			int res=0;
			while(1){
				int cnt1,cnt2;
				cnt1=cnt2=0;
				while(s[l]==i&&l<r){
					l++;
					cnt1++;
				}
				while(s[r]==i&&l<r){
					r--;
					cnt2++;
				}
				if(s[l]!=s[r]){
					res=int_inf;
					break;
				}
				bool flag=false;
				if(s[l]==i){
					flag=true;
				}
				if((l<r)){
					l++;
					r--;
				}
				int k=max(cnt1,cnt2)-min(cnt1,cnt2);
				res+=k;
				if(!(l<r)){ 
					if(s[l]!=s[r]){
						res=int_inf;
					}else{
						if(flag&&s[l]==i&&cnt1) res-=k;
					}
					break;
				}
			}
			// if(res!=int_inf){
				// cout<<(char)i<<endl;
				// cout<<res<<endl;
			// }
			ans=min(ans,res);
		}
		cout<<(ans==int_inf?-1:ans)<<endl;
		// cout<<endl;
	}
	return 0;
}