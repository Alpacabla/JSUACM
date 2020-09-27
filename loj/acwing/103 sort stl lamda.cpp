#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
struct movie{
	int a,b;
	int cnt1,cnt2;
	int ind;
	bool operator < (const movie c) const{
		if(cnt1==c.cnt1) return cnt2>c.cnt2;
		else return cnt1>c.cnt1;
	}
}mo[max_n];
int num[max_n];
int uni[max_n],cnt[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>mo[i].a;
		mo[i].cnt1=mo[i].cnt2=0;
		mo[i].ind=i+1;
	}
	for(i=0;i<m;i++){
		cin>>mo[i].b;
	}
	sort(num,num+n);
	sort(mo,mo+m,[](movie a,movie b) -> bool { return a.a<b.a; });
	for(i=0;i<m;i++){
		uni[i]=mo[i].a;
		cnt[i]=0;
	}
	int len=unique(uni,uni+m)-uni;
	for(i=0;i<n;i++){
		int l=0,r=len-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(num[i]==uni[mid]){
				cnt[mid]++;
				break;
			}
			if(uni[mid]<num[i]){
				l=mid+1;
			}else r=mid-1;
		}
		// int k=lower_bound(mo,mo+m,num[i],[](movie a,int b) -> bool { return a.a<b; })-mo;
		// if(k>=m){
		// 	//cout<<"yes"<<endl;
		// 	continue;
		// }
		// if(mo[k].a==num[i]) mo[k].cnt1++;
	}
	for(i=0;i<m;i++){
		int k=lower_bound(uni,uni+len,mo[i].a)-uni;
		if(k>=len) break;
		mo[i].cnt1=cnt[k];
	}

	sort(mo,mo+m,[](movie a,movie b) -> bool { return a.b<b.b; });
	for(i=0;i<m;i++){
		uni[i]=mo[i].b;
		cnt[i]=0;
	}
	len=unique(uni,uni+m)-uni;
	for(i=0;i<n;i++){
		int l=0,r=len-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(num[i]==uni[mid]){
				cnt[mid]++;
				break;
			}
			if(uni[mid]<num[i]){
				l=mid+1;
			}else r=mid-1;
		}
		// int k=lower_bound(mo,mo+m,num[i],[](movie a,int b) -> bool { return a.b<b; })-mo;
		// if(k>=m){
		// 	//cout<<"no"<<endl;
		// 	continue;
		// }
		// if(mo[k].b==num[i]) mo[k].cnt2++;
	}
	for(i=0;i<m;i++){
		int k=lower_bound(uni,uni+len,mo[i].b)-uni;
		if(k>=len) break;
		mo[i].cnt2=cnt[k];
	}
	sort(mo,mo+m);
	// for(i=0;i<m;i++){
	// 	cout<<mo[i].ind<<" "<<mo[i].cnt1<<" "<<mo[i].cnt2<<" "<<mo[i].a<<" "<<mo[i].b<<endl;
	// }
	cout<<mo[0].ind<<endl;
	return 0;
}