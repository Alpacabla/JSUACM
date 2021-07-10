// Problem: C. Pair Programming
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
		int k,a,b;
		cin>>k>>a>>b;
		vector<int> n1(a+1),n2(b+1);
		for(int i=1;i<=a;i++){
			cin>>n1[i];
		}
		for(int i=1;i<=b;i++){
			cin>>n2[i];
		}
		int l=1,r=1;
		vector<int> ans;
		while(1){
			bool flag=false;
			// while(l<n1.size()&&n1[l]==0){
				// k++;
				// ans.push_back(n1[l]);
				// l++;
				// flag=true;
			// }
			// while(r<n2.size()&&n2[r]==0){
				// k++;
				// ans.push_back(n2[r]);
				// r++;
				// flag=true;
			// }
			while(l<n1.size()&&n1[l]<=k){
				if(n1[l]==0) k++;
				ans.push_back(n1[l]);
				l++;
				flag=true;
			}
			while(r<n2.size()&&n2[r]<=k){
				if(n2[r]==0) k++;
				ans.push_back(n2[r]);
				r++;
				flag=true;
			}
			if(!flag){
				break;
			}
		}
		if(ans.size()==a+b){
			for(auto num:ans){
				cout<<num<<" ";
			}
			cout<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}