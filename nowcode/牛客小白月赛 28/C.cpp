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
string s;
int tot;
ll read_int()
{
	int res=0;
	while(tot<s.size()&&s[tot]<='9'&&s[tot]>='0'){
		res=res*10+s[tot]-'0';
		tot++;
	}
	tot--;
	return 1ll*res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int j;
	cin>>s;
	stack<ll> st;
	while(!st.empty()) st.pop();
	ll ans=0;
	for(tot=0;tot<s.size();tot++){
		int &i=tot;
		if(s[i]=='('){
			st.push(-1);
		}else{
			if(s[i]==')'){
				ll x=1;
				if(i+1!=s.size()){
					if(isdigit(s[i+1])){
						i++;
						x=read_int();
					}
				}
				ll res=0;
				while(st.top()!=-1){
					res+=st.top();
					st.pop();
				}
				st.pop();
				res*=x;
				st.push(res);
			}else{
				if(isdigit(s[i])){
					ll x=read_int();
					ll num=st.top();
					num*=x;
					st.pop();
					st.push(num);
				}else{
					ll a=s[i]-'A'+1;
					st.push(a);
				}
			}
		}
		
		
	}

	while(!st.empty()){
		if(st.top()!=-1){
			ans+=st.top();
		}	
		st.pop();
	}
	cout<<ans<<endl;
	return 0;
}
