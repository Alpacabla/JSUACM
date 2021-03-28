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
struct node{
	int a,b;
	node(){}
	node(int a,int b) :a(a),b(b) {}
	bool operator < (const node c) const {
		return b<c.b;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<node> v;
	vector<vector<int> > ans;
	vector<int> ind;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		swap(a,b);
		v.push_back (node(a,b));
	}
	sort(v.begin(),v.end());
	vector<int> vis(n+1);
	vis[n]=true;
	for(int i=0;i<v.size();i++){
		int &a=v[i].a,&b=v[i].b;
		if(a!=n){
			cout<<"NO"<<endl;
			return 0;
		}
		if(!vis[b]){
			vector<int> t(1,b);
			ans.push_back(t);
			ind.push_back(b);
		}
		vis[b]++;
	}
	// vector<int> toinsert;
	// for(int i=n;i>=1;i--){
	// 	if(!vis[i]){
	// 		toinsert.push_back(i);
	// 	}
	// }
	int now=n;
	int end=ind.size()-1;
	while(1){
		while(now>=1&&vis[now]){
			now--;
		}
		vis[now]=true;
		if(now==0) break;
		while(end>=0&&(ind[end]<now||ans[end].size()==vis[ans[end][0]])){
			end--;
		}
		if(end<0){
			now=-1;
			break;
		}
		ans[end].push_back(now);
	}
	if(now==0){
		cout<<"YES"<<endl;
		for(int i=0;i<ans.size();i++){
			//cout<<n<<" "<<ans[i][0]<<endl;
			ans[i].push_back(ans[i][0]);
			ans[i][0]=n;
			for(int j=1;j<ans[i].size();j++){
				cout<<ans[i][j-1]<<" "<<ans[i][j]<<endl;
			}
		}
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}