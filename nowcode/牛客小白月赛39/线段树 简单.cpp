/*
link: https://ac.nowcoder.com/acm/contest/11216/D
tags: 要特判位置1
	  然后要想到标记2会进化成标记1
	  呜呜呜
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
const int max_n=2e5+5;
int sum[max_n<<3];
int cnt1[max_n<<3];
bool flag[max_n<<3],flag1[max_n<<3];
bool pri[max_n*3];
inline void maintain(int a){
	sum[a]=sum[to_l(a)]+sum[to_r(a)];
	cnt1[a]=cnt1[to_l(a)]+cnt1[to_r(a)];
	return ;
}
void build(int a,int l,int r)
{
	if(l==r){
		int v;
		cin>>v;
		if(!pri[v]){
			sum[a]=1;
		}else{
			if(v==1&&!pri[l]){
				cnt1[a]=1;
			}
		}
		return ;
	}
	int mid=(l+r)>>1;
	build(to_l(a),l,mid);
	build(to_r(a),mid+1,r);
	maintain(a);
	return ;
}
inline void push_down(int a){
	if(flag1[a]){
		sum[to_l(a)]=cnt1[to_l(a)];
		cnt1[to_l(a)]=0;
		if(flag1[to_l(a)]) flag[to_l(a)]=true;
		flag1[to_l(a)]=true;

		sum[to_r(a)]=cnt1[to_r(a)];
		cnt1[to_r(a)]=0;
		if(flag1[to_r(a)]) flag[to_r(a)]=true;
		flag1[to_r(a)]=true;
	}
	if(flag[a]){
		sum[to_l(a)]=0;
		cnt1[to_l(a)]=0;
		flag[to_l(a)]=true;

		sum[to_r(a)]=0;
		cnt1[to_r(a)]=0;
		flag[to_r(a)]=true;
	}
    flag1[a]=flag[a]=0;
	return ;
}
void change(int a,int l,int r,int l1,int r1,int val)
{
	if(l>r1||r<l1) return ;
	if(l>=l1&&r<=r1){
		if(val>=2){
			//if(sum[a]!=0){
				sum[a]=0;
				cnt1[a]=0;
				flag[a]=true;
			//}
		}else{
			//if(cnt1[a]!=0){
				if(flag1[a]) flag[a]=true;
				sum[a]=cnt1[a];
				cnt1[a]=0;
				flag1[a]=true;
			//}
		}
		return ;
	}
	push_down(a);
	int mid=(l+r)>>1;
	change(to_l(a),l,mid,l1,r1,val);
	change(to_r(a),mid+1,r,l1,r1,val);
	//maintain(a);
	return ;
}
int ans=0;
void query(int a,int l,int r,int l1,int r1)
{
	if(l>r1||r<l1) return ;
	if(l>=l1&&r<=r1){
		ans+=sum[a];
		return ;
	}
	push_down(a);
	int mid=(l+r)>>1;
	query(to_l(a),l,mid,l1,r1);
	query(to_r(a),mid+1,r,l1,r1);
	//maintain(a);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    pri[1]=true;
	for(int i=2;i<=5e5;i++){
		if(!pri[i]){
			for(int j=i*2;j<=5e5;j+=i){
				pri[j]=true;
			}
		}
	}

	int n,m;
	cin>>n>>m;
	int vv;
	cin>>vv;
	build(1,2,n);
	for(int i=1;i<=m;i++){
		int v;
		cin>>v;
		int l,r;
        ans=0;
		if(v==1){
			int k;
			cin>>l>>r>>k;
            if(l==1&&!pri[vv]){
                l++;
                ans++;
            }
			if(k!=0){
				change(1,2,n,l,r,k);
			}
		}else{
			cin>>l>>r;
            if(l==1&&!pri[vv]){
                l++;
                ans++;
            }
		}
		query(1,2,n,l,r);
		
		cout<<ans<<endl;
	}
	return 0;
}