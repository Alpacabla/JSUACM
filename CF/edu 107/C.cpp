// Problem: C. Yet Another Card Deck
// Contest: Codeforces - Educational Codeforces Round 107 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1511/problem/C
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
const int max_n=3e5+5;
int a[max_n];
bool vis[55];
bool vis2[max_n];
list<int> li;
vector<int> del;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		int col;
		int res;
		scanf("%d",&col);
		if(!vis[col]){
			vis[col]=true;
			for(int j=1;j<=n;j++){
				if(!vis2[j]&&a[j]==col){
					int add=0;
					for(int k=0;k<del.size();k++){
						if(j>del[k]){
							add++;
						}
					}
					del.push_back(j);
					vis2[j]=true;
					res=j+cnt-add;
					break;
				}
			}
			li.push_front(col);
			cnt++;
		}else{
			int kk=0;
			list<int>::iterator it;
			for(it=li.begin();it!=li.end();it++){
				kk++;
				if(*it==col){
					break;
				}
			}
			res=kk;
			li.erase(it);
			li.push_front(col);
		}
		printf("%d ",res);
	}
	printf("\n");
	return 0;
}