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
const int max_n=2e5+5;
bool vis[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1),sta(n+1);
	vector<int> ans1,ans2;
	int w=0,all=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]>b[i]) w++,sta[i]=1;
		else{
			if(a[i]<b[i]) sta[i]=-1;
			else sta[i]=0;
		}
	}
	for(int i=2;i<=n&&w<=all/2;i++){
		int &x1=a[i],&x2=a[i-1],&y1=b[i],&y2=b[i-1];
		if((x1+x2<=y1+y2&&(sta[i]==1||sta[i-1]==1))||vis[i-1]||(sta[i]==1&&sta[i-1]==1)){
			continue;
		}
		ans1.push_back(i-1);
		ans2.push_back(i);
		vis[i-1]=true;
		vis[i]=true;
		all--;
		if(w>all/2){
			break;
		}
	}
	if(w<=all/2){
		cout<<-1<<endl;
	}else{
		cout<<ans1.size()<<endl;
		for(int i=0;i<ans1.size();i++){
			cout<<ans1[i]<<" "<<ans2[i]<<endl;
		}
	}
	return 0;
}