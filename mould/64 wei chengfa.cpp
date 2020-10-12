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
__int128 read128()
{
	char ch=getchar();
	__int128 res=0;
	while(isdigit(ch)){
		res=res*10+(ch^48);
		ch=getchar();
	}
	return res;
}
void pri128(__int128 a)
{
	char ch[50];
	int ind=0;
	while(a){
		ch[ind++]=(a%10)|48;
		a/=10;
	}
	while(ind>0){
		putchar(ch[--ind]);
	}
	putchar('\n');
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	// //__int128 a,b,p;
	// ull a,b,p;
	// cin>>a>>b>>p;
	// __int128 z,x,c;
	// z=a,x=b,c=p;
	// pri128(z*x%c);
	// // a=read128(),b=read128(),p=read128();
	// // a=a*b%p;
	// // pri128(a);


	ull a,b,p,ans=0;
	cin>>a>>b>>p;
	a%=p;
	b%=p;
	while(b){
		if(b&1) ans=(ans+a)%p;
		a=a*2%p;
		b>>=1;
	}
	cout<<ans<<endl;
	return 0;
}