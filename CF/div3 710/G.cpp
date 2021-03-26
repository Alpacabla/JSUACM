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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	while(n--){
		string s;
		string s1;
		cin>>s1;
		s=" "+s1;
		vector<int> vis(150);
		vector<int> dp(s.size()+5);
		for(int i=s.size()-1;i>=1;i--){
			//dp[i]=vis[s[i]];
			vis[s[i]]++;
		}
		stack<int> sta;
		vector<bool> insta(150);
		s[0]='z'+1;
		sta.push(0);
		for(int i=1;i<s.size();i++){
			vis[s[i]]--;
			if(insta[s[i]]) continue;
			while(s[i]>s[sta.top()]&&vis[s[sta.top()]]!=0){
				insta[s[sta.top()]]=false;
				sta.pop();
			}
			insta[s[i]]=true;
			sta.push(i);
		}
		function< void(stack<int> &sta) > f;
		f = [&s,&f](stack<int> &sta) -> void {
			if(sta.size()==1) return ;
			char ch=s[sta.top()];
			sta.pop();
			f(sta);
			cout<<ch;
			return ;
		};
		f(sta);
		cout<<endl;
	}
	return 0;
}