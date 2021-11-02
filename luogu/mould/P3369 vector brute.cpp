// Problem: P3369 【模板】普通平衡树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3369
// Memory Limit: 128 MB
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
	int q;
	vector<int> a;
	cin>>q;
	while(q--){
		int opt,num;
		cin>>opt>>num;
		switch(opt){
			case 1:{
				auto k=upper_bound(a.begin(),a.end(),num);
				a.insert(k,num);
				break;
			}
				
			case 2:{
				a.erase(lower_bound(a.begin(),a.end(),num));
				break;
			}
			case 3:{
				cout<<(int)(lower_bound(a.begin(),a.end(),num)-a.begin())+1<<endl;
				break;
			}
			case 4:{
				cout<<a[num-1]<<endl;
				break;
			}
			case 5:{
				cout<<(*prev(lower_bound(a.begin(),a.end(),num)))<<endl;
				break;
			}
			case 6:{
				cout<<(*(upper_bound(a.begin(),a.end(),num)))<<endl;
				break;
			}
				
		}
	}
	return 0;
}