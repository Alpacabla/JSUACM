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
    for(i=0;i<n;i++){
        int k=lower_bound(mo,mo+m,num[i],[](movie a,int b) -> bool { return a.a<b; })-mo;
        if(k>=m){
            //cout<<"yes"<<endl;
            continue;
        }
        if(mo[k].a==num[i]) mo[k].cnt1++;
    }
    sort(mo,mo+m,[](movie a,movie b) -> bool { return a.b<b.b; });
    for(i=0;i<n;i++){
        int k=lower_bound(mo,mo+m,num[i],[](movie a,int b) -> bool { return a.b<b; })-mo;
        if(k>=m){
            //cout<<"no"<<endl;
            continue;
        }
        if(mo[k].b==num[i]) mo[k].cnt2++;
    }
    sort(mo,mo+m);
    cout<<mo[0].ind<<endl;
    return 0;
}