#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long int ll;
const int max_n=1e5;
ll dp[25][2][2][2];
ll pp10[20];
ll num;
ll dfs(vector<int> &a,int ind,vector<bool> pre,bool flag,bool last)
{
	if(ind>=a.size()-1) return pre[0];
	
	if(!flag&&dp[ind][pre[0]][pre[1]][pre[2]]!=-1) return dp[ind][pre[0]][pre[1]][pre[2]];
	if(pre[0]) return flag?(num%pp10[a.size()-1-ind]+1):pp10[a.size()-1-ind];


	int lim=flag?a[ind+1]:9;
	ll res=0;
	for(int i=0;i<=lim;i++){
		vector<bool> p(3,false);
		for(int j=0;j<3;j++){
			if(pre[j]) p[(j*10+i)%3]=true;
		}
		if(!(i==0&&last)) p[i%3]=true;
		res+=dfs(a,ind+1,p,flag&&i==lim,last&&i==0);
	}
	return (flag||last)?res:dp[ind][pre[0]][pre[1]][pre[2]]=res;
}
ll solve(ll a)
{
	if(a==0) return 0;
	num=a;
	stack<int> sta;
	while(a){
		sta.push(a%10);
		a/=10;
	}
	vector<int>v(1,0);
	while(sta.size()){
		v.push_back(sta.top());
		sta.pop();
	}
	return dfs(v,0,vector<bool>(3,false),true,true);
}
bool judge(int a)
{
	vector<bool> m(3,false);

	stack<int> sta;
	while(a){
		sta.push(a%10);
		a/=10;
	}
	vector<int>v;
	while(sta.size()){
		v.push_back(sta.top());
		sta.pop();
	}
	for(int i=0;i<v.size();i++){
		vector<bool> mm(3);
		for(int j=0;j<3;j++){
			if(m[j]) mm[((j*10)+v[i])%3]=true;
		}
		mm[v[i]%3]=true;
		if(mm[0]) return true;
		m=mm;
	}
	return false;
}
ll brute(int a)
{
	ll res=0;
	for(int i=1;i<=a;i++){
		res+=judge(i);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	pp10[0]=1;
	for(int i=1;i<=19;i++) pp10[i]=pp10[i-1]*10;
	//memset(dp,-1,sizeof(dp));
	//cout<<solve(1e18)<<endl;
	// cout<<judge(172)<<endl;
	// for(int i=100;i<=10000;i++){
	// 	memset(dp,-1,sizeof(dp));
	// 	if(solve(i)!=brute(i)){
	// 		cout<<i<<endl;
	// 		cout<<solve(i)<<" "<<brute(i)<<endl;
	// 		break;
	// 	}
	// 	cout<<i<<endl;
	// }
	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;
		memset(dp,-1,sizeof(dp));
		ll a=solve(r);
		memset(dp,-1,sizeof(dp));
		ll b=solve(l-1);
		cout<<a-b<<endl;
	}
	return 0;
}