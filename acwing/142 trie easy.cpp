/*
link: https://www.acwing.com/problem/content/description/144/
tags: trie easy
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
const int max_n=1e6+5;
int trie[max_n][30];
const int sz_ind=26;
inline void add_s(string s)
{
	static int tot=0;
	int j=0;
	for(int i=0;i!=s.size();i++){
		j=(trie[j][s[i]-'a']?trie[j][s[i]-'a']:(trie[j][s[i]-'a']=++tot));
	}
	trie[j][sz_ind]++;
	return ;
}
inline int search_s(string s)
{
	int res=0;
	for(int i=0,j=trie[0][s[0]-'a'];j!=0&&i!=s.size();){
		res+=trie[j][sz_ind];
		i++;
		j=trie[j][s[i]-'a'];
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	string s;
	int n,m;
	cin>>n>>m;
	while(n--){
		cin>>s;
		add_s(s);
	}
	while(m--){
		cin>>s;
		cout<<search_s(s)<<endl;
	}
	return 0;
}
