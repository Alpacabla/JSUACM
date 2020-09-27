/*
link: https://www.acwing.com/problem/content/97/
tags: bfs details
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
int sta[(1<<26)+5];
inline bool judge(int x){
	if(x<0||x>24) return false;
	else return true;
}
inline void change(int &a,int x){
	if(judge(x)){
		a=((a^(1<<x)));
	}
	return ;
}
inline void put_next(queue<int> &q,int a,int x,const int cnt){
	change(a,x);
	if(x%5) change(a,x-1);
	if(x%5!=4) change(a,x+1);
	change(a,x+5);
	change(a,x-5);
	if(!sta[a]){
		sta[a]=cnt+1;
		q.push(a);
	}
	return ;
}
void bfs(int a)
{
	queue<int> q;
	while(!q.empty()) q.pop();
	sta[a]=1;
	q.push(a);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		int cnt=sta[t];
		if(cnt==7) continue;
		for(int i=0;i<25;i++){
			put_next(q,t,i,cnt);
		}
	}
	return ;
}
char s[6][6];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	bfs((1<<25)-1);
	int n;
	cin>>n;
	while(n--){
		for(i=0;i<5;i++){
			cin>>s[i];
		}
		int a=1;
		int sum=0;
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				sum+=(s[i][j]=='0'?0:a);
				a<<=1;
			}
		}
		if(sta[sum]>7||sta[sum]==0) cout<<-1<<endl;
		else cout<<sta[sum]-1<<endl;
	}
	return 0;
}
