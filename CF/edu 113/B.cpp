// Problem: B. Chess Tournament
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int cnt1,cnt2;
		cnt1=cnt2=0;
		for(int i=0;i<n;i++){
			cnt1+=s[i]=='1';
			cnt2+=s[i]=='2';
		}
		if(cnt2&&cnt2<=2){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
			vector<string> ss(n);
			int fir=-1,last;
			for(int i=0;i<n;i++) ss[i].resize(n);
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					ss[i][j]='=';
				}
			}
			for(int i=0;i<n;i++){
				//for(int j=0;j<n;j++){
				char ch;
				ss[i][i]='X';
				if(s[i]=='1'){
					for(int k=0;k<n;k++){
						if(k!=i){
							ss[i][k]='=';
							ss[k][i]='=';
						}
					}
				}else{
					if(fir==-1){
						fir=i;
						last=i;
					}else{
						ss[last][i]='+';
						ss[i][last]='-';
						last=i;
					}
				}
			}
			if(fir!=-1){
				ss[last][fir]='+';
				ss[fir][last]='-';
			}
			for(int i=0;i<n;i++) cout<<ss[i]<<endl;
		}
	}
	return 0;
}