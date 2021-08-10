#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int t,k;
double rtx,rty,lx,ly,rx,ry;
double cal(double ax,double ay,double bx,double by)
{
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lf%lf%lf%lf%lf%lf",&k,&rtx,&rty,&lx,&ly,&rx,&ry);
        double len=cal(lx,ly,rx,ry);
        double xb=cal(rtx,rty,lx,ly);
        double h=sqrt(xb*xb-(len*len)/4.0);
        double ans=len*h/2.0;
        //cout<<ans<<endl;
        double sd=len,xd,add=len;
        int cnt=0;
        int lim=min(200,k-2);
        for(int i=0;i<lim;i++)
        {
            //if((add*h/2.0)<1e-12)break;
            cnt++;
            xd=add/2.0+sd;//cout<<ans<<" "<<sd<<" "<<xd<<endl;
            ans+=(sd+xd)*h/2.0;
            sd=xd;add/=2.0;
        }
        ans+=(sd+xd)*h/2.0*(k-2-cnt);
        printf("%.3f\n",ans);
    }
}
