// Problem: B. Take Your Places!
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
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
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		int cnt1,cnt2;
		cnt1=cnt2=0;
		
		vector<int> ind1,ind2;
		for(int i=1;i<=n;i++){
			if(i%2) ind1.push_back(i);
			else ind2.push_back(i);
		}
		ll ans=ll_inf;
		int j=0;
		ll temp=0;
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]%2==1){
				if(j<ind1.size()){
					temp+=abs(i-ind1[j]);
					j++;
				}else{
					flag=false;
					break;
				}
			}
		}
		if(flag&&j==ind1.size()){
			ans=min(ans,temp);
		}
		temp=0;
		j=0;
		flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]%2==1){
				if(j<ind2.size()){
					temp+=abs(i-ind2[j]);
					j++;
				}else{
					flag=false;
					break;
				}
			}
		}
		if(flag&&j==ind2.size()){
			ans=min(ans,temp);
		}
		cout<<(ans==ll_inf?-1:ans)<<endl;
	}
	return 0;
}