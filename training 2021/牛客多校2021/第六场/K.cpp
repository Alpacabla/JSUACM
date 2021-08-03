#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define int long long
const int inf=0x3f3f3f3f;
int n,m,a[200010];
vector<int> ans[100010];
signed main()
{
    cin>>n>>m;
    int mx=0,sum=0;
    for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]),sum+=a[i];
    if(m>=n){
        for(int i=1;i<=n;i++)
            cout<<1<<" "<<i<<" "<<0<<" "<<a[i]<<endl;
    }
    else{
        int tmp=sum;
        sum=sum/m;
        if(tmp%m)sum++;
        int s=max(mx,sum);
        //cout<<s<<endl;
            int t=s,cnt=1,last=0;
            for(int i=1;i<=n;i++)
            {
                 if(t>=a[i])
                 {
                     //cout<<t<<endl;
                     cout<<1<<" "<<cnt<<" "<<last<<" "<<last+a[i]<<endl;
                    if(t==a[i])cnt++,last=0,t=s;
                     else
                     last+=a[i],t-=a[i];
                 }
                 else
                 {
                     cout<<2<<" "<<cnt<<" "<<last<<" "<<s<<" "<<cnt+1<<" "<<0<<" "<<a[i]-(s-last)<<endl;
                     cnt++,t=s-(a[i]-(s-last)),last=a[i]-(s-last);
                 }
            }

    }
}