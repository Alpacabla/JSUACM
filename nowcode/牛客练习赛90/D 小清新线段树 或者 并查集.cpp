// Problem: 妄想集合
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11180/D
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
const int max_n=1e5+5;
int pa[max_n];
vector<int> a[max_n];
int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
void merge(int a,int b)
{
	a=find(a),b=find(b);
	if(a==b) return ;
	else{
		pa[a]=b;
		return ;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		a[i].push_back(b);
	}
	while(m--){
		string s;
		int l,r;
		cin>>s>>l>>r;
		if(s[0]=='A'){
			vector<int> vv;
			for(int i=l;i<=r&&vv.size()<50;i++){
				for(int j=0;j<a[i].size()&&vv.size()<50;j++){
					vv.push_back(a[i][j]);
				}
			}
			bool flag=false;
			if(vv.size()==50){
				flag=true;
			}else{
				sort(vv.begin(),vv.end());
				for(int i=0;!flag&&i<((int)vv.size())-2;i++){
					if(vv[i]+vv[i+1]>vv[i+2]){
						flag=true;
					}
				}
			}
			cout<<(flag?"YES":"NO")<<endl;
		}else{
			int val;
			cin>>val;
			while(l<=r){
				l=find(l);
				if(l>r) break;
				a[l].push_back(val);
				if(a[l].size()==50){
					merge(l,l+1);
				}
				l++;
			}
		}
	}
	return 0;
}