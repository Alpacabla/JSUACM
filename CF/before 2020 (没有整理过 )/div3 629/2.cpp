#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define ull 		unsigned long long
#define ll 			long long
#define M 			1000000007
#define pb 			push_back
#define p_q 		priority_queue
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios	    	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp 			make_pair
#define lb 			lower_bound
#define ub			upper_bound
#define F           first
#define S           second
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ini(a,n,b)	for(ll int i=0;i<n;i++) a[i]=0;
#define cset(a)		__builtin_popcountll(a)
#define hell 		(ull)1e9
#define re 			resize
#define un(a)		a.resize(unique(a.begin(),a.end())-a.begin())




signed main(void)
{ios
	#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	#endif 
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		rep(i,0,n)
		cin>>a[i];
		if(n==1){
			cout<<1<<endl;
			cout<<1<<endl;
			continue;
		}
		if(n==2){
			if(a[0]==a[1]){
				cout<<1<<endl;
				cout<<1<<" "<<1<<endl;
			}
			else{
				cout<<2<<endl;
				cout<<1<<" "<<2<<endl;
			}
			continue;
		}
		vector<int> t(a,a+n);
		vector<int> ans(n);
		un(t);
		if(sz(t)==1)
		{
			cout<<1<<endl;
			rep(i,0,n)
			cout<<1<<" ";
			cout<<endl;
			continue;
		}
		ans[0]=1;
		if(sz(t)%2==0){
			rep(i,1,n)
			{
				if(a[i]==a[i-1])
					ans[i]=ans[i-1];
				else
					ans[i]=3-ans[i-1];
			}
		}
		else{
			if(sz(t)==n){
				rep(i,1,n-1)
				ans[i]=3-ans[i-1];
				ans[n-1]=3-2*(a[n-1]==a[0]);
			}
			else{
				int u=1;
				rep(i,1,n){
					if(a[i]==a[i-1]){
						if(u)
							ans[i]=3-ans[i-1],u=0;
						else
							ans[i]=ans[i-1];
					}
					else
						ans[i]=3-ans[i-1];
				}
			}

		}
		set<int>p(all(ans));
		cout<<sz(p)<<endl;
		rep(i,0,n)
		cout<<ans[i]<<" ";
		cout<<endl;
	}
}