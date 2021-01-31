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
	int t;
	cin>>t;
	while(t--){
		int n;
		string s1,s2;
		cin>>n;
		cin>>s1>>s2;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(s1[i]>s2[i]) cnt++;
			if(s1[i]<s2[i]) cnt--;
		}
		if(cnt==0) cout<<"EQUAL"<<endl;
		else if(cnt<0) cout<<"BLUE"<<endl;
		else cout<<"RED"<<endl;
	}
	return 0;
}