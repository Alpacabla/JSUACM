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
int size[max_n],cnt[max_n],fa[max_n],val[max_n],son[max_n][2];
int ind,root;
inline void clear(int x){
	size[x]=cnt[x]=fa[x]=val[x]=son[x][0]=son[x][1]=0;
}
inline bool isleft(int x){
	return x==son[fa[x]][0];
}
inline void maintain(int x){
	size[x]=size[son[x][0]]+size[son[x][1]]+cnt[x];
}
inline void rotate(int x)
{
	int y=fa[x],yy=fa[y],chk=isleft(x),t=son[x][chk];
	son[y][chk^1]=t,fa[t]=y;
	son[x][chk]=y,fa[y]=x;
	fa[x]=yy;
	if(yy) son[yy][son[yy][1]==y]=x;
	size[x]=size[y];
	maintain(y);
	//maintain(x);
	return ;
}
void splay(int x)
{
	for(int i=fa[x];i;rotate(x),i=fa[x]){
		if(fa[i]) rotate(isleft(x)==isleft(i)?i:x);
	}
	root=x;
	return ;
}
void insert(int v)
{
	if(!root){
		val[++ind]=v;
		cnt[ind]=size[ind]=1;
		root=ind;
		return ;
	}
	int now=root,f=0;
	while(now&&val[now]!=v){
		f=now;
		now=son[now][val[now]<v];
	}
	if(now!=0){
		cnt[now]++;
		size[now]++;
		if(f!=0) size[f]++;
	}else{
		val[++ind]=v;
		fa[ind]=f;
		son[f][val[f]<v]=ind;
		cnt[ind]=size[ind]=1;
		size[f]++;
		now=ind;
	}
	splay(now);
	return ;
}
int rk(int v)
{
	int now=root,res=0;
	while(1){
		if(v<val[now]){
			if(son[now][0]) now=son[now][0];
			else break;
		}else{
			res+=size[son[now][0]];
			if(v==val[now]){
				res+=1;
				break;
			}
			res+=cnt[now];
			if(son[now][1]) now=son[now][1];
			else break;
		}
	}
	splay(now);
	return res;
}
int kth(int k)
{
	int now=root;
	while(1){
		if(son[now][0]&&k<=size[son[now][0]]){
			now=son[now][0];
		}else{
			k-=size[son[now][0]]+cnt[now];
			if(k<=0){
				break;
			}
			now=son[now][1];
		}
	}
	splay(now);
	return val[now];
}
//flag 1 是查询前驱，0是查询后驱，查询之前先insert(v)，让v旋转到根
int preORnxt(const int flag)
{
	int now=son[root][flag^1];
	while(son[now][flag]) now=son[now][flag];
	splay(now);
	return val[now];
}
void del(int v)
{
	rk(v);
	if(cnt[root]>1){
		cnt[root]--;
		size[root]--;
		return ;
	}
	if(!son[root][0]&&!son[root][1]){
		clear(root);
		root=0;
		return ;
	}
	if(!son[root][0]||!son[root][1]){
		int t=son[root][!son[root][0]];
		fa[t]=0;
		clear(root);
		root=t;
		return ;
	}
	int t=root;
	preORnxt(1);
	fa[son[t][1]]=root;
	son[root][1]=son[t][1];
	clear(t);
	maintain(root);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	root=0;
	ind=0;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		switch(a){
			case 1:
				insert(b);
				break;
			case 2:
				del(b);
				break;
			case 3:
				cout<<rk(b)<<endl;
				break;
			case 4:
				cout<<kth(b)<<endl;
				break;
			case 5:
				insert(b);
				cout<<preORnxt(1)<<endl;
				del(b);
				break;
			case 6:
				insert(b);
				cout<<preORnxt(0)<<endl;
				del(b);
				break;
		}
	}
	return 0;
}