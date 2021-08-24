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
int next1[max_n];
int s[max_n];
void get_next1(vector<int> &s)
{
	int t;
	int i;
	int k;
	next1[0]=-1;
	next1[1]=0;
	for(i=1;i<s.size();i++){
		k=i;
		t=next1[i];
		while(s[t]!=s[i]){
			k=t;
			t=next1[t];
			if(t==-1) {
				break;
			}
		}
		next1[i+1]=next1[k]+1;
	}//ababbcababa
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	reverse(a.begin(),a.end());
	get_next1(a);
	int k=a.size()-1,p=1;
	for(int i=0;i<a.size();i++){
		int &nxt=next1[i+1];
		int x,y;
		x=a.size()-i-1;
		y=i+1-nxt;
		if(x+y<=k+p){
			if(x+y<k+p){
				k=x;
				p=y;
			}else{
				if(y<p){
					k=x;
					p=y;
				}
			}
		}
	}
	cout<<k<<" "<<p<<endl;
	return 0;
}