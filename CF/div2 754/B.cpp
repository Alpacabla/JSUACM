// Problem: B. Reverse Sort
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		auto check=[](string s) -> bool{
			bool flag=true;
			for(int i=1;i<s.size();i++){
				if(s[i]<s[i-1]) flag=false;
			}
			return flag;
		};
		vector<int> out;
		bool flag=true;
		if(!(flag=check(s))){
			int cnt=0;
			vector<int> z;
			for(int i=0;i<s.size()&&!flag;i++){
				if(s[i]=='0') continue;
				z.push_back(i);
				cnt++;
				int k=0;
				int res=0;
				vector<int> zz=z;
				stack<int> sta;
				for(int j=s.size()-1;k!=cnt&&j>=0;j--){
					if(s[j]=='1') continue;
					if(s[j]=='0') k++;
					sta.push(j);
				}
				while(sta.size()){
					zz.push_back(sta.top());
					sta.pop();
				}
				assert(k==cnt);
				assert(i>=res);
				string ss=s;
				for(int i=0;i<cnt;i++){
					swap(ss[zz[i]],ss[zz[i+cnt]]);
				}
				if(check(ss)){
					flag=true;
					out=zz;
				}
			}
		}
		cout<<(out.size()?1:0)<<endl;
		if(out.size())	cout<<out.size()<<" ";
		for(int i=0;i<out.size();i++){
			cout<<out[i]+1<<" ";
		}
		if(out.size()) cout<<endl;
	}
	return 0;
}