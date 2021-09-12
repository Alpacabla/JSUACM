// Problem: D. Inconvenient Pairs
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
vector<int> visx[max_n],visy[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		vector<int> x(n),y(m);
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<m;i++){
			cin>>y[i];
		}
		x.push_back(1e6+1);
		y.push_back(1e6+1);
		vector<pair<int,int> >coor(k); 
		for(int i=0;i<k;i++){
			cin>>coor[i].first>>coor[i].second;
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		sort(coor.begin(),coor.end());
		vector<pair<int,int> >cx,cy;
		vector<int> stax,stay;
		
		for(int i=0;i<coor.size();i++){
			int &xx=coor[i].first,&yy=coor[i].second;
			int v=*lower_bound(x.begin(),x.end(),xx);
			int vv=*lower_bound(y.begin(),y.end(),yy);
			if(v==xx&&vv!=yy){
				cx.push_back(coor[i]);
				stax.push_back(xx);
				visx[xx].push_back(yy);
			}
			if(v!=xx&&vv==yy){
				cy.push_back(coor[i]);
				stay.push_back(yy);
				visy[yy].push_back(xx);
			}
		}
		for(int i=0;i<stax.size();i++){
			sort(visx[stax[i]].begin(),visx[stax[i]].end());
		}
		sort(cx.begin(),cx.end(),[](const pair<int,int> a,const pair<int,int> b) -> bool{
			return a.second<b.second;
		});
		ll ans=0;
		for(int i=0;i<cx.size();i++){
			int &xx=cx[i].first,&yy=cx[i].second;
			auto k=*lower_bound(y.begin(),y.end(),yy);
			auto kk=upper_bound(cx.begin(),cx.end(),make_pair((int)1e6+5,k),[](const pair<int,int> a,const pair<int,int> b) -> bool{
					return a.second<b.second;
				});
			ans+=(int)(kk-cx.begin())-1-i;
			int kkk=upper_bound(visx[xx].begin(),visx[xx].end(),k)-lower_bound(visx[xx].begin(),visx[xx].end(),yy);
			ans-=kkk-1;
		}
		
		for(int i=0;i<cy.size();i++){
			int &xx=cy[i].first,&yy=cy[i].second;
			auto k=*lower_bound(x.begin(),x.end(),xx);
			auto kk=upper_bound(cy.begin(),cy.end(),make_pair(k,(int)1e6+5),[](const pair<int,int> a,const pair<int,int> b) -> bool{
					return a.first<b.first;
				});
			ans+=(int)(kk-cy.begin())-1-i;
			int kkk=upper_bound(visy[yy].begin(),visy[yy].end(),k)-lower_bound(visy[yy].begin(),visy[yy].end(),xx);
			ans-=kkk-1;
		}
		cout<<ans<<endl;
		for(int i=0;i<stax.size();i++) visx[stax[i]].clear();
		for(int i=0;i<stay.size();i++) visy[stay[i]].clear();
	}
	return 0;
}