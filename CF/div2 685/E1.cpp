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
	vector<int> num(n+1);
	int ab,bc,ac;
	int t1,t2,t3,t4,t5,t6;
	cout<<"XOR "<<1<<" "<<2<<endl;
	cout.flush();
	cin>>t1;
	cout<<"AND "<<1<<" "<<2<<endl;
	cout.flush();
	cin>>t2;
	ab=t1+2*t2;

	cout<<"XOR "<<2<<" "<<3<<endl;
	cout.flush();
	cin>>t3;
	cout<<"AND "<<2<<" "<<3<<endl;
	cout.flush();
	cin>>t4;
	bc=t3+2*t4;

	t5=t1^t3;
	cout<<"AND "<<1<<" "<<3<<endl;
	cout.flush();
	cin>>t6;
	ac=t5+2*t6;

	int a,b,c;
	num[1]=(ab+ac-bc)/2;
	num[2]=(ab+bc-ac)/2;
	num[3]=(bc+ac-ab)/2;
	for(int i=4;i<=n;i++){
		cout<<"XOR 1 "<<i<<endl;
		cout.flush();
		int k;
		cin>>k;
		num[i]=k^num[1];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
	return 0;
}