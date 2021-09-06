#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=5e5+5;
int val[max_n<<2],vall[max_n<<2],valr[max_n<<2];
ll sum[max_n<<2];
int lenl[max_n<<2],lenr[max_n<<2];
bool flag[max_n<<2];
int to[max_n];
inline ll xx(int len){
	return (1ll+len)*len/2;
}
inline void maintain(int ind){
    int l=to_l(ind),r=to_r(ind);
    vall[ind]=vall[l];
    valr[ind]=valr[r];
    lenl[ind]=lenl[l];
    lenr[ind]=lenr[r];
    if(valr[l]<=vall[r]){
    	sum[ind]=sum[l]+sum[r]-xx(lenl[r])-xx(lenr[l])+xx(lenl[r]+lenr[l]);
    }else sum[ind]=sum[l]+sum[r];
    
	flag[ind]=false;
	if(valr[l]<=vall[r]){
		flag[ind]=flag[l]&flag[r];
		if(flag[l]){
			lenl[ind]=lenl[l]+lenl[r];
		}
		if(flag[r]){
			lenr[ind]=lenr[r]+lenr[l];
		}
	}
    return ;
}
int now=0;
inline void change(int ind,int a){
    val[ind]=vall[ind]=valr[ind]=a;
    lenl[ind]=lenr[ind]=1;
    sum[ind]=1;
    flag[ind]=true;
    return ;
}
void build(int l,int r,int ind)
{
    if(l==r){
        ll a;
        cin>>a;
        change(ind,a);
        to[++now]=ind;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,to_l(ind));
    build(mid+1,r,to_r(ind));
    maintain(ind);
    return ;
}
void update(int x,int y)
{
    int ind=to[x];
    change(ind,y);
    ind/=2;
    while(ind!=0){
        maintain(ind);
        ind/=2;
    }
    return ;
}
vector<int> ansto;
void query(int l,int r,int l1,int r1,int ind)
{
    if(r<l1||l>r1) return ;
    if(l>=l1&&r<=r1){
        ansto.push_back(ind);
        return ;
    }
    int mid=(l+r)>>1;
    query(l,mid,l1,r1,to_l(ind));
    query(mid+1,r,l1,r1,to_r(ind));
    return ;
}
ll solve()
{
	ll res=0;
	int last=0;
	for(int i=1;i<ansto.size();i++){
		int &ind=ansto[i],&l=ansto[i-1];
		if(flag[ind]){
			if(valr[l]<=vall[ind]){
				last+=lenl[ind];
			}else{
				res+=xx(last);
				last=lenl[ind];
			}
		}else{
			if(valr[l]<=vall[ind]){
				last+=lenl[ind];
				res-=xx(lenl[ind]);
			}
			res+=sum[ind];
			res-=xx(lenr[ind]);
			res+=xx(last);
			last=lenr[ind];
		}
	}
	res+=xx(last);
	return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j;
    int n,q;
    cin>>n>>q;
    build(1,n,1);
    while(q--){
        int a;
        cin>>a;
        if(a==2){
            int l,r;
            cin>>l>>r;
            if(l>r) swap(l,r);
            ansto.clear();
            ansto.push_back(0);
            query(1,n,l,r,1);
            
            cout<<solve()<<endl;
        }else{
            int x,y;
            cin>>x>>y;
            update(x,y);
        }
    }
    return 0;
}