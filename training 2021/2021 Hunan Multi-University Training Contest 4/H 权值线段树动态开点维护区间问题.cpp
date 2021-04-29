/*
link: https://vjudge.net/contest/433955#problem/H
tags: 如标题，但是看别的学校的代码有一个非常好写的维护是
      维护这个点和下个点是否不一样，然后修改的时候就修改
      两个点，查询就查询整个区间的和是否等于区间长度。
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int max_n=1e5+10;
int lson[max_n<<5],rson[max_n<<5];
int flag[max_n<<5];
int lval[max_n<<5],rval[max_n<<5];
const int lim=1e9;
int tot=1;
inline void maintain(int l,int mid,int r,int ind)
{
    lval[ind]=lval[lson[ind]];
    rval[ind]=rval[rson[ind]];
    if((mid-l+1==1&&flag[rson[ind]])||(r-mid==1&&flag[lson[ind]])||(flag[lson[ind]]&&flag[rson[ind]])){
    	flag[ind]=(rval[lson[ind]]==!lval[rson[ind]]);
    }else{
    	flag[ind]=false;
    }
    return ;
}
int update(int k,int ind,int l=1,int r=lim)
{
    int now=ind;
    if(now==0){
        now=++tot;
    }
    if(l==r){
        flag[now]=1;
        lval[now]=rval[now]=!lval[now];
        return now;
    }
    int mid=(l+r)>>1;
    if(k<=mid) lson[now]=update(k,lson[ind],l,mid);
    else rson[now]=update(k,rson[ind],mid+1,r);
    maintain(l,mid,r,now);
    return now;
}
bool fff=true;
bool ans=true;
bool last;
void query(int ind,int l1,int r1,int l=1,int r=lim)
{
	if(l>r1||r<l1) return ;
	if(r<=r1&&l>=l1){
		if(!ind){
            //cout<<'x'<<endl;
			if(l!=r){
				ans=false;
			}
			if(fff){
				fff=false;
			}else{
				if(l==r&&last==0){
					ans=false;
				}
			}
			last=0;
		}else{
            // cout<<l<<" "<<r<<endl;
            // cout<<flag[ind]<<endl;
            // cout<<"u"<<endl;
			if(!flag[ind]){
				ans=false;
			}
			if(fff){
				fff=false;
			}else{
				if(last!=!lval[ind]){
					ans=false;
				}
			}
			last=rval[ind];
		}
		return ;
	}
	int mid=(l+r)>>1;
	query(lson[ind],l1,r1,l,mid);
	query(rson[ind],l1,r1,mid+1,r);
	return ;
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    int root=0;
    for(int i=1;i<=m;i++){
        int k;
        scanf("%d",&k);
        root=update(k,root);
    }
    for(int i=1;i<=q;i++){
        int opt;
        scanf("%d",&opt);
        if(opt==1){
            int x;
            scanf("%d",&x);
            root=update(x,root);
        }else{
            int x,y;
            scanf("%d%d",&x,&y);
            fff=true;
            ans=true;
            query(root,x,y);
            if(ans) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}