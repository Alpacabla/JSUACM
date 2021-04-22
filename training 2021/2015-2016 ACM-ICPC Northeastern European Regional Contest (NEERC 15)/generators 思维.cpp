#include<bits/stdc++.h>
using namespace std;
#pragma optimize(3)
#define ll long long
struct node
{
    int x,a,b,c;
}p[100010];
int idx[100010],id[100010];
vector<int>v[100010];
int main()
{
    int n,k;
    freopen("generators.in", "r", stdin);
    freopen("generators.out", "w", stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].a>>p[i].b>>p[i].c;
    }
    for(int i=0;i<n;i++)
    {
        v[i].push_back(p[i].x);
        for(int j=1;j<p[i].c;j++)
        {
            v[i].push_back((p[i].a*v[i][j-1]+p[i].b)%p[i].c);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int mx=-1;
        for(int j=0;j<p[i].c;j++)
           if(v[i][j]>mx)
           {
               mx=v[i][j];
               idx[i]=j;
           }
        ans+=mx;
    }
    if(ans%k!=0)
    {
        printf("%d\n",ans);
        for(int i=0;i<n;i++)
            printf("%d ",idx[i]);
        printf("\n");
    }
    else
    {
        int mi=-1;
        int x=-1,y=-1;
        for(int i=0;i<n;i++)
        {
            int res=ans-v[i][idx[i]];
            for(int j=0;j<p[i].c;j++)
            {
                if((res+v[i][j])%k!=0&&res+v[i][j]>mi){
                    mi=res+v[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        if(mi==-1){
            cout<<-1<<endl;
        }else{
            idx[x]=y;
            printf("%d\n",mi);
            for(int i=0;i<n;i++)
                printf("%d ",idx[i]);
            printf("\n");
        }
    }
}
//123