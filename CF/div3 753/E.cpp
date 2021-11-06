// Problem: E. Robot on the Board 1
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int sta[200][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	sta['L'][0]=0;
	sta['L'][1]=-1;
	sta['R'][0]=0;
	sta['R'][1]=1;
	sta['U'][0]=-1;
	sta['U'][1]=0;
	sta['D'][0]=1;
	sta['D'][1]=0;
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		int lx,rx,ly,ry;
		lx=rx=ly=ry=1;
		int x=1,y=1;
		int ansx=1,ansy=1;
		bool flag=true;
		int tx,ty;
		for(int i=0;i<s.size();i++){
			x+=sta[s[i]][0],y+=sta[s[i]][1];
			lx=min(lx,x);
			rx=max(rx,x);
			ly=min(ly,y);
			ry=max(ry,y);
			if(rx-lx>=n||ry-ly>=m){
				flag=false;
				break;
			}
			ansx=2-lx;
			ansy=2-ly;
			
		}
		cout<<ansx<<" "<<ansy<<endl;
	}
	return 0;
}