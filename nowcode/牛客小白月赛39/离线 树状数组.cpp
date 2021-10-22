/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=3e6+5;
bool vis[max_n];
int bit[max_n];
void add(int a){
	while(a<max_n){
		bit[a]++;
		a+=lowbit(a);
	}
	return ;
}
int query(int a){
	int res=0;
	while(a){
		res+=bit[a];
		a-=lowbit(a);
	}
	return res;
}
bool pri[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	pri[1]=true;
	for(int i=2;i<max_n;i++){
		if(!pri[i]){
			for(int j=i+i;j<max_n;j+=i){
				pri[j]=true;
			}
		}
	}
	int n;
	cin>>n;

	add(1);
	vector<tuple<int,int,int>> ask(n+1);
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		ask[i]={b,a,i};
	}
	vector<int> ans(n+1);
	int last=1;
	sort(ask.begin()+1,ask.end());
	for(int i=1;i<=n;i++){
		int a,k;
		int v=0;
		k=get<0>(ask[i]),a=get<1>(ask[i]);
		while(last<=k){
			if(!pri[last]){
				for(int j=last*2;j<max_n;j+=last){
					if(!vis[j]){
						vis[j]=true;
						add(j);
						if(j<=100){
							v++;
						}
					}
				}
			}
			last++;
		}
		cout<<v<<endl;
		ans[get<2>(ask[i])]=a-query(a);
	}
    for(int i=1;i<=n;i++){
    	cout<<ans[i]<<endl;
    }
	return 0;
}