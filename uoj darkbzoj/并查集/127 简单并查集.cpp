/*
link: 
tags: 
*/
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
unordered_map<int,int> mp;
inline int find(int a){
	int &k=mp[a];
	return k?k=find(k):a;
}
inline void con(int a,int b){
	a=find(a),b=find(b);
	if(a!=b) mp[a]=b;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		mp.clear();
		cin>>n;
		vector<int> ind(n+1),a(n+1),b(n+1),c(n+1);
		
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ind[i]=i;
		}
		sort(ind.begin()+1,ind.end(),[&c](const int a,const int b) -> bool{
			return c[a]>c[b];
		});
		bool flag=true;
		for(int i=1;i<=n&&flag;i++){
			int &aa=a[ind[i]],&bb=b[ind[i]],&cc=c[ind[i]];
			if(cc){
				con(aa,bb);
			}else{
				if(find(aa)==find(bb)){
					flag=false;
				}
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}