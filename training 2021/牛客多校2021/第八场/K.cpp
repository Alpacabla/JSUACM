#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double esp = 1e-7;
const double PI = acos(-1);
signed main()
{
    int t;
    __int128 pi=PI*1e15;
    //cout<<(long long)(PI*1e8)<<endl;
    scanf("%d",&t);
    while(t--) {
        double w,d;
        scanf("%lf%lf",&w,&d);
        double m = min(w,d);
        __int128 l=sqrt(w*w+d*d)*1e15;
        __int128 k=m*1e15;

        ll ans=0;
        int s=0,lim=pi/l;
        
        while(s<=lim){
            int len=(lim-s);
            int i1=(s+len*0.382),i2=(s+len*0.618);
            int res1=(4+i1*3+(int)((pi-(l*i1))/k)*2);
            int res2=(4+i2*3+(int)((pi-(l*i2))/k)*2);
            ans=max(ans,res1);
            ans=max(ans,res2);
            if(res1<res2){
                s=i1+1;
            }else{
                lim=i2-1;
            }
        }
        printf("%lld\n",ans);
//         __int128 mm=pi%k;
//         __int128 cnt=pi/k;
//         __int128 res;
//         if(cnt<(mm/(l-k))) res=cnt;
//         else res=mm/(l-k);
//         //cout<<(long long)cnt*2<<endl;
//         ll ans1=(long long)cnt*2+4+(long long)res;
        
//         __int128 mm1=pi%l;
//         __int128 cnt1=pi/l;
//         __int128 res1;
//         if(mm1>=k) res1=2;
//         else res1=0;
//         ll ans2=(long long)cnt1*3+4+(long long)res1;
//         cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}