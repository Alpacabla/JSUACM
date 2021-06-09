// Problem: D. Omkar and Medians
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/D
// Memory Limit: 256 MB
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
		int n;
		cin>>n;
		set<int> sets;
		//int now=(3*n+1)/2;
		int last;
		bool flag=true;
		int cnt1,cnt2;
		cnt1=cnt2=0;
		set<int>::iterator ind;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(!flag) continue;
			if(i==1){
				//sets.insert(k);
			}else{
				if(k==last){
					
				}else{
					if(k<last){
						if(ind==sets.begin()||*prev(ind)<=k){
							
						}else{
							flag=false;
						}
					}else{
						if(next(ind)==sets.end()||*next(ind)>=k){
							
						}else{
							flag=false;
						}
						
					}
				}
			}
			sets.insert(k);
			ind=sets.find(k);
			last=k;
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}