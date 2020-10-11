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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> ans1(n),ans2(n);
		stack<int> num;
		while(!num.empty()) num.pop();
		for(i=1;i<=n;i++){
			num.push(i);
		}
		int ans=0;
		for(i=1;i<n;i++){
			int a,b;
			a=num.top();
			num.pop();
			b=num.top();
			num.pop();
			ans1[i]=a,ans2[i]=b;
			ans=(a+b);
			if(ans%2) ans+=1;
			ans/=2;
			num.push(ans);
		}
		cout<<ans<<endl;
		for(i=1;i<n;i++){
			cout<<ans1[i]<<" "<<ans2[i]<<endl;
		}
		// stack<int> odd,even;
		// vector<int> ans1(0),ans2(0);
		// while(!odd.empty()) odd.pop();
		// while(!even.empty()) even.pop();
		// for(i=1;i<=n;i++){
		// 	if(i%2) odd.push(i);
		// 	else even.push(i);
		// }
		// int ans=0;
		// bool flag=true;
		// for(i=1;i<n;i++){
		// 	int a=-1,b=-1;
		// 	if(even.size()>=2&&(odd.size()<2||flag)){
		// 		a=even.top();
		// 		even.pop();
		// 		b=even.top();
		// 		even.pop();
		// 		ans1.push_back(a),ans2.push_back(b);
		// 		a+=b;
		// 		a/=2;
		// 		ans=a;
		// 		if(a%2) odd.push(a);
		// 		else even.push(a);
		// 		continue;
		// 	}
		// 	if(odd.size()>=2&&(even.size()<2||flag)){
		// 		a=odd.top();
		// 		odd.pop();
		// 		b=odd.top();
		// 		odd.pop();
		// 		//cout<<a<<" "<<b<<endl;
		// 		ans1.push_back(a),ans2.push_back(b);
		// 		a+=b;
		// 		a/=2;
		// 		ans=a;
		// 		if(a%2) odd.push(a);
		// 		else even.push(a);
		// 		continue;
		// 	}
		// 	flag=!flag;
		// 	//cout<<even.top()<<" "<<odd.top()<<endl;
		// 	ans1.push_back(even.top()),ans2.push_back(odd.top());
		// 	ans=even.top()+odd.top();
		// 	if(ans%2) ans+=1;
		// 	ans/=2;
		// }
		// cout<<ans<<endl;
		// for(i=0;i<n-1;i++){
		// 	cout<<ans1[i]<<" "<<ans2[i]<<endl;
		// }
	}
	return 0;
}
