#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int max_n=2e5+5;
ll a[max_n];
bool vis[max_n];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll min1=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        min1=min(min1,a[i]);
    }
    ll sum=0;

    deque<ll> q;
    for(int i=1;i<m;i++){
        sum+=a[i];
        q.push_back(i);
    }

    ll ans=0;

    for(int i=m;i<=n;i++){
        sum+=a[i];
        if(i>=m+1&&vis[i-m]){
            sum-=a[i-m];
        }
        while(q.size()&&q.front()+m<=i){
            sum-=a[q.front()];
            q.pop_front();
        }
        q.push_back(i);
        if(sum<0){
            continue;
        }else{
            while(sum>=0){
                int j=q.back();
                ll temp=a[j];
                a[j]=max(min1,a[j]-sum-1);
                ans+=temp-a[j];
                sum-=(temp-a[j]);
                if(a[j]==min1){
                    vis[j]=true;
                    q.pop_back();
                }
            }
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++){
        printf("%lld ",a[i]);
    }
    printf("\n");
    return 0;
}