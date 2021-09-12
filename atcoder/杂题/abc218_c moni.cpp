// Problem: C - Shapes
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_c
// Memory Limit: 1024 MB
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
const int max_n=200+5;
char s1[max_n][max_n],s2[max_n][max_n];
char t[max_n][max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>(s1[i]+1);
	}
	for(int i=1;i<=n;i++){
		cin>>(s2[i]+1);
	}
	vector<pair<int,int> >z;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s2[i][j]=='#'){
				z.push_back({i,j});
			}
		}
	}
	vector<pair<int,int> >zz;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s1[i][j]=='#'){
				zz.push_back({i,j});
			}
		}
	}
	if(zz.size()!=z.size()){
		cout<<"No"<<endl;
		return 0;
	}
	if(z.size()==0){
		cout<<"Yes"<<endl;
		return 0;
	}
	auto f=[](vector<pair<int,int> > &z) -> void{
		int x=z[0].first,y=z[0].second;
		for(int i=0;i<z.size();i++){
			z[i].first-=x;
			z[i].second-=y;
		}
		return ;
	};
	f(z);
	f(zz);
	bool flag=false;
	if(z==zz){
		flag=true;
	}
	zz.clear();
	for(int i=n,x=1;i>=1;i--,x++){
		for(int j=n,y=1;j>=1;j--,y++){
			if(s1[i][j]=='#'){
				zz.push_back({x,y});
			}
		}
	}
	f(zz);
	if(z==zz){
		flag=true;
	}
	
	zz.clear();
	for(int i=1,x=1;i<=n;i++,x++){
		for(int j=n,y=1;j>=1;j--,y++){
			if(s1[j][i]=='#'){
				zz.push_back({x,y});
			}
		}
	}
	f(zz);
	if(z==zz){
		flag=true;
	}
	
	zz.clear();
	for(int i=n,x=1;i>=1;i--,x++){
		for(int j=1,y=1;j<=n;j++,y++){
			if(s1[j][i]=='#'){
				zz.push_back({x,y});
			}
		}
	}
	f(zz);
	if(z==zz){
		flag=true;
	}
	
	cout<<(flag?"Yes":"No")<<endl;
	return 0;
}