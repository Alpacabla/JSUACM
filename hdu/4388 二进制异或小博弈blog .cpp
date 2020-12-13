/*
link: http://acm.hdu.edu.cn/showproblem.php?pid=4388
tags: 当去掉技能看的时候，可以看出二进制上只剩一个1的时候才不能移动
	  当分解一个数量为n的堆的时候 n = k ^ (k ^ n) ， 留下的两个堆 k 和 k ^ n 中加起来的1的数量
	  和原来堆中的1数量的奇偶性是一样的，因为 1 = 1 ^ 0 , 0 = 1 ^ 1 || 0 = 0 ^ 0 
	  这么看肯定是同奇偶，且很容易证明取的次数一定是有限的，所以最后一个堆能分解成 1 +- 2*x个不能移动的
	  堆，所以一个堆可移动次数只与其二进制上1的个数有关。很显然堆是相互独立的且是可叠加的奇偶性博弈。

	  接着考虑技能时可以发现 k ^ n 与 (k << 1) ^ n 的异或结果中有的1也是同奇偶的，实际上 a ^ b 中
	  1的个数只与 a,b 中的1的个数有关。
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
	int n,t;
	int now=1;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		while(n--){
			int a;
			cin>>a;
			int cnt=0;
			while(a){
				cnt+=(a&1);
				a>>=1;
			}
			ans+=cnt-1;
		}
		cout<<"Case "<<now++<<": ";
		if(ans%2==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}