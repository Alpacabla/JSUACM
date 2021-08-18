#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double esp = 1e-7;
struct node {
	int x,id,best,worst;
}a[maxn];
int b[maxn];
bool cmp(node a,node b) {
	return a.x<b.x;
}
bool cmp2(node a,node b) {
	return a.id<b.id;
}
signed main() 
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x,a[i].id = i;
		for(int i=1;i<=n;i++) cin>>b[i];
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n);
		int rank;
		for(int i=1;i<=n;i++) {
			int res = a[i].x+b[1],l = 2,r = n,rank = 1;
			for(int j=1;j<=n && l<=r;j++) {
				if(i == j) continue;
				if(a[j].x + b[r] > res) {
					rank++;
					r--;
				} else {
					l++;
				}
			}
			//cout<<rank<<endl;
			a[i].worst = rank;
		}
		
		for(int i=1;i<=n;i++) {
			int res = a[i].x+b[n],l = 1,r = n-1,rank = 1;
			for(int j=n;j>=1 && l<=r;j--){
				if(i == j) continue;
				if(a[j].x + b[l] <= res){
					l++;
				}else{
					r--;
					rank++;
				}
			}
			//cout<<rank<<endl;
			a[i].best = rank;
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++) {
			cout<<a[i].best<<" "<<a[i].worst<<endl;
		}
	}
}
