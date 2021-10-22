/*
link: 
tags: 
*/
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    ll out=0;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        deque<int> sta;
        while(n){
            sta.push_back(n%2);
            n/=2;
        }
        while(sta.front()==0){
            sta.pop_front();
        }
        ll ans=0;
        int cnt=0;
        while(sta.size()){
            ans+=(1ll<<(cnt++))*(sta.back());
            sta.pop_back();
        }
        out+=ans;
    }
    cout<<out<<endl;
	
	return 0;
}